CFLAGS=-Wall #-O2
CC=ccpsx

# Compilation targets
# Makefile for GNU Make 3.81

# Build pxfinder module and a source example using it
# You only need to build pxfinder.obj once

main: pxfinder
	$(CC) $(CFLAGS) -DPXFINDER -Xo$$80010000 pxfinder.obj $@.c -o MAIN.cpe
	cpe2psx MAIN.cpe
	copy MAIN.PSX C:\psyq\emulators\ePSXe190\MAIN.EXE
	copy MAIN.PSX C:\psyq\emulators\nopsx\MAIN.EXE
	copy MAIN.PSX C:\psyq\tools\psxserial-012\MAIN.EXE

pxfinder:
	$(CC) $(CFLAGS) -Xo$$80100000 -c $@.c

clean:
	del *.o
	del *.cpe
	del *.sym
	del *.map
	del *.exe
	del *.psx
	del pxfinder.obj