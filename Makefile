# $Id: Makefile,v 1.2 2004/10/12 09:06:17 marquet Exp $
##############################################################################

ROOTDIR=.

CC	= gcc
CFLAGS	= -Wall -ansi -pedantic
CFLAGS  += -g
LIBDIR  = $(ROOTDIR)/lib
INCDIR  = -I$(ROOTDIR)/include
LIBS    = -L$(LIBDIR) -lhardware

###------------------------------
### Main targets 
###------------------------------------------------------------
BINARIES= mi_kernel
OBJECTS	= $(addsuffix .o,\
	  mi_kernel)

all: $(BINARIES) $(OBJECTS)


###------------------------------
### Main rules 
###------------------------------------------------------------
mi_kernel.o: mi_kernel.c
	$(CC) $(CFLAGS) -c mi_kernel.c $(INCDIR)

mi_user.o: mi_user.c
	$(CC) $(CFLAGS) -c mi_user.c $(INCDIR)

mi_kernel: mi_kernel.o mi_user.o
	$(CC) $(CFLAGS) -o mi_kernel mi_kernel.o mi_user.o $(LIBS)

###------------------------------
### Misc.
###------------------------------------------------------------
.PHONY: clean realclean depend
clean:
	$(RM) *.o $(BINARIES)
realclean: clean 
	$(RM) vdiskA.bin vdiskB.bin
