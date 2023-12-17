#define FERROR "Error reading file"

typedef struct Filelist {
  int rows;
  int **columns;
} filelist;

int readinput(filelist *flist);
void dec1();


