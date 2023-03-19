#include "stdio.h"
#include <sys/types.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <libmath.h>

#include "pxfinder.h"

void __pxfinder_Tim_Load();
void __pxfinder_initPrn();
void __pxfinder_readPad();
void __pxfinder_initCursor();
void __pxfinder_drawCursor(GsOT ot);
void __pxfinder_drawCoords(int f);

unsigned char __pxfinder_cursor[] = {
0x10,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x0c,0x02,0x00,0x00,0x00,0x03,0xff,
0x01,0x00,0x01,0x01,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,
0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x4c,0x02,0x00,0x00,0xf4,0x03,0xe7,0x01,
0x0c,0x00,0x18,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00
};

u_long __padd, __prn;
float __x = 150, __y = 150;
GsSPRITE __curSpr;
DISPENV __dispenv;

RECT curRect;

struct RECTF
{
	float x;
	float y;
	float w;
	float h;
} curPrn = { 30.0, 30.0, 55.0, 25.0 };

void __pxfinder_readPad()
{
	/* Calculate cursor center */
	float center_x, center_y;
	center_x = __x + (__curSpr.w / 2);
	center_y = __y + (__curSpr.h / 2);
	
	__padd = PadRead(0);

	/* Move the cursor */
	if( (__padd & PADLup) && center_y > 0 )										__y -= move_offset;
	if( (__padd & PADLdown)	&& center_y < (__dispenv.disp.h - move_offset) )	__y += move_offset;
	if( (__padd & PADLleft)	&& center_x > 0 )									__x -= move_offset;
	if( (__padd & PADLright) && center_x < (__dispenv.disp.w - move_offset) )	__x += move_offset;
	
	/* Move the FntPrint box (in case it bothers) */
	if( (__padd & PADL1) && (curPrn.x+move_offset > 0))								{ curPrn.x -= move_offset; __pxfinder_initPrn(); }
	if( (__padd & PADL2) && ((curPrn.x+curPrn.w+move_offset) < __dispenv.disp.w))	{ curPrn.x += move_offset; __pxfinder_initPrn(); }
	if( (__padd & PADR1) && (curPrn.y+move_offset > 0))								{ curPrn.y -= move_offset; __pxfinder_initPrn(); }
	if( (__padd & PADR2) && (curPrn.y+curPrn.h+move_offset) < __dispenv.disp.h)		{ curPrn.y += move_offset; __pxfinder_initPrn(); }
}

void __pxfinder_Tim_Load()
{
	GsIMAGE *image;

	/* Initialize our GsIMAGE to the contents of our TIM.
		We skip the TIM ID and version (magic) by adding
		0x4 to the pointer */
	GsGetTimInfo((u_long *)(__pxfinder_cursor + 4), image);

	curRect.x = image->px;
	curRect.y = image->py;
	curRect.w = image->pw;
	curRect.h = image->ph;
	LoadImage(&curRect, image->pixel);

	if ((image->pmode & 3) < 2)
	{
		curRect.x = image->cx;
		curRect.y = image->cy;
		curRect.w = image->cw;
		curRect.h = image->ch;
		LoadImage(&curRect, image->clut);
	}
}

void __pxfinder_initPrn()
{
	FntLoad(960, 256);
	__prn = FntOpen(curPrn.x, curPrn.y, curPrn.w, curPrn.h, 1, 10);
}

void __pxfinder_initCursor()
{
	__curSpr.attribute=0x1000000;			/*8 bit image with CLUT*/
	__curSpr.x = __x;
	__curSpr.y = __y;
	__curSpr.w = 24;
	__curSpr.h = 24;

	/* 1 Tpage = 64 pixels in 16 bit mode and 128 in 8 bit*/
	__curSpr.tpage = 31;
	
	/*Normal luminosity*/
	__curSpr.r = __curSpr.g = __curSpr.b = 128;

	/*TPage offset*/
	__curSpr.u=104; // 52 pixels * 2 since it's 8bit
	__curSpr.v=231; // 256 + 231 = 487
   
	/*CLUT location in frame buffer*/
	__curSpr.cx = 768;
	__curSpr.cy = 511;
   
	/*Scaling and rotation*/
	__curSpr.mx = 0;
	__curSpr.my = 0;
	__curSpr.scalex = ONE;
	__curSpr.scaley = ONE;
	__curSpr.rotate = 0;
}

void __pxfinder_drawCursor(GsOT ot)
{
	GsSortFastSprite(&__curSpr, &ot, 0);
}

void __pxfinder_drawCoords(int f)
{
	float center_x, center_y;
	center_x = __x + (__curSpr.w / 2);
	center_y = __y + (__curSpr.h / 2);

	FntPrint(__prn, "%d,%d", (int)center_x, (int)center_y);
	if (f == 1)
		FntFlush(__prn);
}

/* API */

void pxfinder_init()
{
	GetDispEnv(&__dispenv);

	__pxfinder_Tim_Load();
	__pxfinder_initPrn();
}

void pxfinder_draw(GsOT ot, int f)
{
	__pxfinder_readPad();
	__pxfinder_initCursor();
	__pxfinder_drawCursor(ot);
	__pxfinder_drawCoords(f);
}