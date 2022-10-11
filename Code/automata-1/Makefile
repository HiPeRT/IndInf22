CC=gcc
CSRCS=automata-1-solution.cpp
CFLAGS=
#CFLAGS=-Wall
LDFLAGS=-l stdc++
EXENAME=automata-1.exe

all: clean
	${CC} ${CSRCS} -o ${EXENAME} ${CFLAGS} ${LDFLAGS}

clean:
	rm ${EXENAME}

run: all
	./${EXENAME}