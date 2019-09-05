# PXfinder

A tool for Playstation 1 to retrieve screen coordinates using a crosshair

This is a simple obj module to move a crosshair and reading its [x,y] coordinates.
Useful when you want to place sprites on screen and don't want to perform dozens of builds
just to find the right coordinates on screen.

This tool is just a small TIM image with a FntPrint().

It should also work on interlaced screens.

In order to use pxfinder to need to:
- link the provided pxfinder.obj file into your Makefile chain
- modify your source program in order to use pxfinder
- if you want, you can customize the speed of movement of the crosshair and the coordinates
box (MOVE_OFFSET in pxfinder.h)

If you want to compile pxfinder yourself, there are two Makefiles: `Makefile` is for GNU Make, `Makefile.mak` is for Psymake.

Your source file needs to be modified in two points:
```
/* init pxfinder */
pxfinder_init();

/* draw the crosshair and the coordinates box (f=1 execute FntFlush immediately */
pxfinder_draw(GsOT ot, int f);
```
Linking example:

`ccpsx -Xm -Xo$80010000 -DPXFINDER pxfinder.obj main.c -omain.cpe`

`-DPXFINDER` in your code enables pxfinder. Example usage is in the `main.c` file.

Use the DPAD to move the crosshair.
L1/L2 and R1/R2 to move the coordinates box.

**Bug**: since the crosshair and the coordinates box move in float steps, depending on the
offset choosen you may not be able to get exactly of the edge of the screen. A better
version could implement a dynamic resolution movement.
