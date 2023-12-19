#define FERROR "Error: Could not read file\n"
#define RERROR "Error: No row count\n"
#define CERROR "Error: columns not allocated\n"

typedef struct Filelist {
  int rows;
  int *columnSize;
  char **columns;
} filelist;

int readinput(filelist *flist);
int allocateFileMemory(filelist *flist, char *FILENAME);
void freeMemoryForFilelist(filelist *myFilelist);
int readFile(filelist *flist, char *FILENAME);
void dec1(void);


