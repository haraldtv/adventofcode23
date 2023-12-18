#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "headers/dec1.h"

/*
int readInput(list *flist) {
    char c;
    flist->rows = 0;
    flist->columns = 0;
    FILE *fptr;
    fptr = NULL;
    int temp = 0;

    fptr = fopen("files/dec1_input.txt", "r");

    if (!fptr) {
        printf("Error reading file\n");
        return 1;
    }

    for (c = getc(fptr); (c != EOF); c = getc(fptr)) {
        if (c == '\n') {
            flist->rows++;
            if (flist->columns > temp) {
                temp = flist->columns;
            }
            flist->columns = 0;
        }
        else
            flist->columns++;
    }
    flist->columns = temp;
    
    // After counting EOL, the last line will have EOF, not EOL, and as such the count will be one short
    flist->rows++;

    printf("Rows: %d\n", flist->rows);
    printf("Columns: %d\n", flist->columns);

    return 0;

}

void december1() {
  list flist;
  readInput(&flist);
  char *strings;
  strings = malloc(flist.rows * flist.columns * sizeof(char));
  int i, j  = 0;
  char c;
  
  FILE *fptr;
  fptr = fopen("files/dec1_input.txt", "r");

  for (c = getc(fptr); c != EOF; c = getc(fptr)) {
    if (c == '\n') {
      i++;
    }
    strings[i+j] = c;
    j++;
    
  }
  for (i=0;i<flist.rows;i++) {
    printf("%s\n", )
  }
}
*/

int main() {
  dec1();
  return 0;
}
