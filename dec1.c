#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "headers/dec1.h"

int readinput(filelist *flist) {
  
  return 0;
}

uint8_t rowcount(char *FILENAME, int *count) {
  char c;
  *count = 0;

  FILE *fptr;
  fptr = fopen(FILENAME, "r");

  if (!fptr) {
    printf(FERROR);
    return 1;
  }
  
  for (c = getc(fptr); c != EOF; c = getc(fptr)) {
    if (c == '\n') {
      *count += 1;
    }
  }
  *count += 1;
  return 0;
}

void dec1() {
  clock_t start, end;
  double cpu_time_used;

  filelist flist;
  start = clock();
  printf("Returncode: %d\n", rowcount("files/dec1_input.txt", &flist.rows));
  end = clock();
  printf("%d\n", flist.rows);

  cpu_time_used = ( (double) (end - start)) / CLOCKS_PER_SEC;
  printf("Execution time: %f s\n", cpu_time_used);
}
