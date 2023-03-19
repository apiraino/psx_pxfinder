#include "stdio.h"

#include <sys/types.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>

#define OT_LENGTH	10
#define	PACKET_SIZE	4
#define PACKETMAX 20

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#include "BG.h"

#ifdef PXFINDER
#include "pxfinder.h"
float move_offset = 1.3;
#endif

int CurrentBuffer = 0;
GsOT myOT;
GsOT_TAG myOT_TAG[1<<OT_LENGTH];
PACKET GPUPacketArea[PACKET_SIZE * PACKETMAX];

GsSPRITE bgSpr;
extern unsigned char BG[];

void Tim_Load(unsigned char *adrs);
void initBG();

int main(void)
{
	u_long padd;

	SetVideoMode(MODE_PAL);

	GsInitGraph(SCREEN_WIDTH, SCREEN_HEIGHT, GsNONINTER|GsOFSGPU, 1, 0);
	GsDefDispBuff(0, 0, 0, SCREEN_HEIGHT);

	myOT.length = OT_LENGTH;
	myOT.org = myOT_TAG;
	GsClearOt(0,0,&myOT);

#ifdef PXFINDER
	// Load before any other sprite
	pxfinder_init();
#endif
	
	PadInit(0);

	Tim_Load(BG);
	
	while (! (padd & PADstart) )
	{
		padd = PadRead(0);

		GsSetWorkBase((PACKET*)GPUPacketArea);
		GsClearOt(0,0,&myOT);
		GsSortClear(60,60,60,&myOT);

#ifdef PXFINDER
		pxfinder_draw(myOT, 1); // 1 = flush
#endif

		// Load a BG (just for demonstration purposes)
		initBG();

		GsSwapDispBuff();
		DrawSync(0);
		VSync(0);
		GsSortClear(60,60,60,&myOT);
		GsDrawOt(&myOT);
	}

	PadStop();
	ResetGraph(0);
	StopCallback();

	return 0;
}

void Tim_Load(unsigned char *adrs)
{
	RECT	rect;
	GsIMAGE *image;

	/* We skip the TIM ID and version (magic) by adding
		0x4 to the pointer */
	GsGetTimInfo((u_long *)(adrs + 4), image);

	rect.x = image->px;
	rect.y = image->py;
	rect.w = image->pw;
	rect.h = image->ph;
	LoadImage(&rect, image->pixel);

	if ((image->pmode & 3) < 2)
	{
		rect.x = image->cx;
		rect.y = image->cy;
		rect.w = image->cw;
		rect.h = image->ch;
		LoadImage(&rect, image->clut);
	}
}

void initBG()
{
	bgSpr.attribute=0x1000000; /* 8bit image */
	bgSpr.w = 256;
	bgSpr.h = 256;
	bgSpr.r = bgSpr.g = bgSpr.b = 128;
	bgSpr.u=0;
	bgSpr.v=0;
	bgSpr.cx = 0;
	bgSpr.cy = 481;
	bgSpr.mx = 0;
	bgSpr.my = 0;
	bgSpr.scalex = ONE;
	bgSpr.scaley = ONE;
	bgSpr.rotate = 0;

	/* 1st texture page */
	bgSpr.x = 0;
	bgSpr.y = 0;
	bgSpr.tpage = 5;
	GsSortFastSprite(&bgSpr, &myOT, 0);
	
	/* 2nd texture page */
	bgSpr.x = 256;
	bgSpr.tpage = 7;
	GsSortFastSprite(&bgSpr, &myOT, 0);
}