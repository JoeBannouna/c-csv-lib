#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COL_SIZE 100

typedef struct CSVFILE {
  char* filename;
  char*** rows;
  int rows_num;
  int* rows_sizes;
} CSVFILE;


CSVFILE* initCSVFILE(char* filename);

void addRowSize(CSVFILE* file_ptr, int size);

void addRow(CSVFILE* file_ptr, char** row, int row_size);

void printRows(CSVFILE* file_ptr);

void saveRows(CSVFILE* file_ptr);