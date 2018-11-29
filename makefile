# build an executable named myprog from myprog.c
all: tempRead.c 
	gcc -g -Wall -o tempRead tempRead.c

clean: 
	$(RM) tempRead
