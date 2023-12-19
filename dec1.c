#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>

#include "headers/dec1.h"

#define INPUTFILE "files/dec1_input.txt"
#define ASCIICONVERTINT 48

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

  do{
    c = getc(fptr);
    if ((c == '\n') || (c == EOF)) {
      flist->columnSize[count] = charcount;
      count += 1;
      charcount = 0;
    }
    else {
      flist->columns[count][charcount] = c;
      charcount += 1;
    }
  } while (c != EOF);
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
  printf("flist.rows: %d\n", flist.rows);

  cpu_time_used = ( (double) (end - start)) / CLOCKS_PER_SEC;
  printf("Execution time: %f s\n", cpu_time_used);

  allocateFileMemory(&flist, INPUTFILE);
  readFile(&flist, INPUTFILE);

  int64_t sum = 0;
  int i, j;
  int first, last;

  printf("Debugging info\n");
  printf("--------\n");
  printf("flist.rows: %d\n", flist.rows);

  printf("Row length:\n");
  for (i=0; i<flist.rows; i++) {
    printf("flist.columnSize[%d]: %d\n", i, flist.columnSize[i]);
  }

  for (i=0; i<flist.rows; i++) {
    for (j=0; j<flist.columnSize[i]; j++) {
      if (isdigit(flist.columns[i][j])) {
        printf("Digit [%d][%d]: %d\n", i, j, ((flist.columns[i][j] - ASCIICONVERTINT)*10));
        printf("flist.columns[%d][%d]: %d\n", i, j, (flist.columns[i][j]));
        sum += ((flist.columns[i][j] - ASCIICONVERTINT) * 10);
        printf("Sum: %d\n", sum);
        break;
      }
    }
    for (j = (flist.columnSize[i] -1); j>=0; j--) {
      if (isdigit(flist.columns[i][j])) {
        printf("Digit [%d][%d]: %d\n", i, j, (flist.columns[i][j] - ASCIICONVERTINT));
        printf("flist.columns[%d][%d]: %d\n", i, j, (flist.columns[i][j]));
        sum += (flist.columns[i][j] - ASCIICONVERTINT);
        printf("Sum: %d\n", sum);
        break;
      }
    }
  }
  printf("--------\n");

  printf("Total sum: %d\n", sum);


  freeMemoryForFilelist(&flist);
}
