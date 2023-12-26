CC  = gcc
RM  = /bin/rm -f
DEBUG   = -g
LIBS    = -lm
CFLAGS  = -O -Wall ${DEBUG}
LDFLAGS = 

OBJS    = kadai1-sub.o KDI-1_yomiage.o
PROGS   = program

all : ${PROGS}

program : ${OBJS}
	${CC} ${LDFLAGS} -o program ${OBJS} ${LIBS}

.c.o :
	${CC} ${CFLAGS} -c $<

.PHONY : clean
clean :
	${RM} ${OBJS} *~