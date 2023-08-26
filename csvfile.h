#ifndef CSVFILE_STRUCT_INCLUDE
#define CSVFILE_STRUCT_INCLUDE

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

// Initializes a new CSVFile struct
CSVFILE* CSVFinit(char* filename);

void CSVFaddRowSize(CSVFILE* file_ptr, int size);

void CSVFinsertRowSize(CSVFILE* file_ptr, int size, int row_index);

void CSVFdelRowSize(CSVFILE* file_ptr, int index);

void CSVFprintRows(CSVFILE* file_ptr);

void CSVFaddRow(CSVFILE* file_ptr, char** row, int row_size);

void CSVFinsertRow(CSVFILE* file_ptr, char** row, int row_size, int row_index);

void CSVFreadRows(CSVFILE* file_ptr);

void CSVFprintRowsSizes(CSVFILE* file_ptr);

void CSVFsaveRows(CSVFILE* file_ptr);

void CSVFdelRow(CSVFILE* file_ptr, int row_index);

void CSVFfreeMem(CSVFILE* file_ptr);

#endif