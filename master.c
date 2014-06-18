#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>

double getValue(int expSize, int fracSize, unsigned long long bits);
double singlePrecision(unsigned long long num);
void *testRange(void *p);

static int const array_index_threshold = 1;

struct message {
  unsigned long long start;
  unsigned long long end;
  int id;
};

int main (int argc, char *argv[]) {
  if(argc != 4) {
    fprintf(stderr, "---> USAGE: ./executable [start] [end] [number of nodes to assign chunk]\n");
    exit(-1);
  } else {
    printf("Start = %s, End = %s\n", argv[1], argv[2]);
  }

  // This two dimensional array holds the value[index] with 2 options
  // Option 1: [index][start], could also be most current starting point
  // Option 2: [index][end], end point or could also mean, left off location
  int nodes = atoi(argv[3]);
  unsigned long long value[nodes][2];

  struct message *p;
  if((p = (struct message *) malloc (sizeof(struct message))) == NULL) {
    fprintf(stderr, "ERROR: mallocing struct message *p\n");
    exit(-1);
  }

  /* Setup variables, and get ready to divide by number of children */
  unsigned long long start, end, temp, chunk;
  start = atoll(argv[1]);
  end = atoll(argv[2]);
  temp = 0;
  chunk = (end / nodes);

  int i;
  for(i = 1; i <= nodes; i++) {
    if(i == 1) { /*This should be first element in the array*/
        value[i][1] = start;
        temp = (start + chunk);
        value[i][2] = temp - array_index_threshold;
    } else {
        value[i][1] = value[i-1][2] + array_index_threshold;
        temp = (temp + chunk);
        value[i][2] = temp - array_index_threshold;
    }
    fprintf(stdout, "ID: %d, start = %llu, end = %llu\n", i, value[i][1], value[i][2]);
  }
  return 0;
}
