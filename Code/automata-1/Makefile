CC=gcc
CSRCS=automata-1-solution.cpp runtime/unix/nextCharLib.cpp
CFLAGS=
ALL_CFLAGS= -I runtime/ ${CFLAGS}
#CFLAGS=-Wall
LDFLAGS=-l stdc++
EXENAME=automata-1

all: 
	${CC} ${CSRCS} -o ${EXENAME} ${ALL_CFLAGS} ${LDFLAGS}

clean:
	rm ${EXENAME}

run: all
	./${EXENAME}