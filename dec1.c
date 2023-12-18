#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "headers/dec1.h"

#define INPUTFILE "files/dec1_sample.txt"

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

  fclose(fptr);
  return 0;
}

int allocateFileMemory(filelist *flist, char *FILENAME) {
  printf("%d\n", flist->rows);

  register int i, j;

  int count = 0;
  int charcount = 0;
  char c;

  FILE *fptr;
  fptr = fopen(FILENAME, "r");

  if (!fptr) {
    printf(FERROR);
    return 1;
  }

  // Allocate memory to store column sizes
  flist->columnSize = (int*)malloc(flist->rows * sizeof(int));

  // Allocate memory for each row to later be filled
  flist->columns = (char**)malloc(flist->rows * sizeof(char *));

  // Allocate enough memory to store all the characters in a line
  for (i=0; i<flist->rows; i++) {
    flist->columns[i] = (char*)malloc(100 * sizeof(char));
  }

  fclose(fptr);
  return 0;
}

void freeMemoryForFilelist(filelist *myFilelist) {
    for (int i = 0; i < myFilelist->rows; ++i) {
        free(myFilelist->columns[i]);
    }
    free(myFilelist->columns);
}

int readFile(filelist *flist, char *FILENAME) {
  register int i, j;

  int count = 0;
  int charcount = 0;
  char c;

  FILE *fptr;
  fptr = fopen(FILENAME, "r");

  // Allocate enough memory to store all the characters in a line
  for (c = getc(fptr); c != EOF; c = getc(fptr)) {
    if (c == '\n') {
      flist->columnSize[count] = charcount;
      count += 1;
      charcount = 0;
    }
    else {
      flist->columns[count][charcount] = c;
      charcount += 1;
    }
  }
  count += 1;

  fclose(fptr);
  return 0;
}

void dec1() {
  clock_t start, end;
  double cpu_time_used;

  filelist flist;
  start = clock();
  printf("Returncode: %d\n", rowcount(INPUTFILE, &flist.rows));
  end = clock();
  printf("%d\n", flist.rows);

  cpu_time_used = ( (double) (end - start)) / CLOCKS_PER_SEC;
  printf("Execution time: %f s\n", cpu_time_used);

  allocateFileMemory(&flist, INPUTFILE);
  readFile(&flist, INPUTFILE);
  printf("%c\n", flist.columns[1][0]);
  printf("%d\n", flist.columnSize[0]);

  int8_t sum;
  int i, j;
  int first, last;

  for (i=0; i<flist.rows; i++) {
    for (j=0; j<flist.columnSize[i]; j++) {

    }
  }


  freeMemoryForFilelist(&flist);
}
