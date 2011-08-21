#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>

/* This is our thread function.  It is like main(), but for a thread*/
void *threadFunc(void *arg) {
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 1 ) {
		usleep(1);
		printf("threadFunc says: %s\n",str);
		++i;
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t pth;
	int i = 0;

	pthread_create(&pth, NULL, threadFunc, "foo");
	
	while(i < 5) {
		usleep(1);
		printf("main is running...\n");
		++i;
	}

	printf("main waiting for thread to terminate...\n");
	pthread_join(pth, NULL);

	return 0;
}