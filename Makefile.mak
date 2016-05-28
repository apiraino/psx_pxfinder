# -----------------------------------------
#       PlayStation 1 Psy-Q Makefile
# Sony Computer Entertainment Europe (SCEE)
# -----------------------------------------

# Build pxfinder module and a source example using it
# You only need to build pxfinder.obj once

all:
	del *.map
	del *.sym
	del *.exe
	del *.cpe
	del pxfinder.obj
	cls

	ccpsx -Xm -Xo$80010000 -c pxfinder.c
	ccpsx -Xm -Xo$80010000 -DPXFINDER pxfinder.obj main.c -omain.cpe,main.sym,mem.map
	cpe2x /ce main.cpe