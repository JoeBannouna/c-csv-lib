#include <stdbool.h>
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

void insertRowSize(CSVFILE* file_ptr, int size, int row_index);

void delRowSize(CSVFILE* file_ptr, int index);

void printRowSizes(CSVFILE* file_ptr);

void addRow(CSVFILE* file_ptr, char** row, int row_size);

void insertRow(CSVFILE* file_ptr, char** row, int row_size, int row_index);

void printRows(CSVFILE* file_ptr);

void saveRows(CSVFILE* file_ptr);

void delRow(CSVFILE* file_ptr, int row_index);

void delCSVFILE(CSVFILE* file_ptr);