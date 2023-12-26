CC  = gcc
RM  = /bin/rm -f
DEBUG   = -g
LIBS    = -lm
CFLAGS  = -O -Wall ${DEBUG}
LDFLAGS = 

OBJS    = compile-main.o compile-func.o
PROGS   = program

all : ${PROGS}

program : ${OBJS}
	${CC} ${LDFLAGS} -o program ${OBJS} ${LIBS}

.c.o :
	${CC} ${CFLAGS} -c $<

.PHONY : clean
clean :
	${RM} ${OBJS} *~