CC = gcc
CFLAGS = -Wall -g  -o

all: master thread

master:
	$(CC) $(CFLAGS) master master.c -lpthread

thread:
	$(CC) $(CFLAGS) thread thread.c -lpthread
	
clean:
	rm -rf ./master ./thread ./*.*~ ./*~ ./*.dSYM