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

int rowcount(char *FILENAME, int *count) {
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
  register int i;

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
  int count = 0;
  int charcount = 0;
  char c;

  FILE *fptr;
  fptr = fopen(FILENAME, "r");

  if (!fptr) {
    printf(FERROR);
    return 1;
  }


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

int findAndReplaceNumbers(filelist *flist) {
  if (!flist->rows) {
    printf(RERROR);
    return 1;
  }
  else if (flist->columns == NULL) {
    printf(CERROR);
    return 1;
  } 
  
  filelist templist = {
    .rows = flist->rows,
    .columns = NULL,
    .columnSize = NULL
  };



  return 0;
}

void dec1(void) {
  clock_t start, end;
  double cpu_time_used;

  filelist flist = {
    .rows = 0,
    .columnSize = NULL,
    .columns = NULL
  };

  start = clock();
  printf("Returncode: %d\n", rowcount(INPUTFILE, &flist.rows));
  end = clock();
  printf("flist.rows: %d\n", flist.rows);

  cpu_time_used = ( (double) (end - start)) / CLOCKS_PER_SEC;
  printf("Execution time: %f s\n", cpu_time_used);

  start = clock();
  allocateFileMemory(&flist, INPUTFILE);
  readFile(&flist, INPUTFILE);

  int sum = 0;
  int i, j;

  for (i=0; i<flist.rows; i++) {
    for (j=0; j<flist.columnSize[i]; j++) {
      if (isdigit(flist.columns[i][j])) {
        sum += ((flist.columns[i][j] - ASCIICONVERTINT) * 10);
        break;
      }
    }
    for (j = (flist.columnSize[i] -1); j>=0; j--) {
      if (isdigit(flist.columns[i][j])) {
        sum += (flist.columns[i][j] - ASCIICONVERTINT);
        break;
      }
    }
  }

  printf("Total sum: %d\n", sum);
  end = clock();
  cpu_time_used = ( (double) (end - start)) / CLOCKS_PER_SEC;
  printf("Execution time: %f s\n", cpu_time_used);


  freeMemoryForFilelist(&flist);
}
