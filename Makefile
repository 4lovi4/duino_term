CC = gcc
CLEAN = rm -f
TARGET = duino_term
SOURCE = main.c term.c
DEFINES = -DDEBUG_DUINO

all : ${TARGET}

${TARGET} : ${SOURCE:.c=.o}
	${CC} ${SOURCE:.c=.o} -o $@

${SOURCE:.c=.o} : ${SOURCE}
	${CC} ${DEFINES} -c ${SOURCE}

clean : 
	${CLEAN} *.o ${TARGET}
		


