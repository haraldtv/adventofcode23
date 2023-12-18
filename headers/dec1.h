#define FERROR "Error reading file"

typedef struct Filelist {
  int rows;
  int *columnSize;
  char **columns;
} filelist;

int readinput(filelist *flist);
int allocateFileMemory(filelist *flist, char *FILENAME);
void freeMemoryForFilelist(filelist *myFilelist);
int readFile(filelist *flist, char *FILENAME);
void dec1();


