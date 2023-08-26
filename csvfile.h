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

// Adds a row-size to the list that tracks row-sizes in memory
void CSVFaddRowSize(CSVFILE* file_ptr, int size);

// Inserts a row-size at a certain index
void CSVFinsertRowSize(CSVFILE* file_ptr, int size, int row_index);

// Deletes a row-size at a certain index
void CSVFdelRowSize(CSVFILE* file_ptr, int index);

// Prints rows of the CSV file struct
void CSVFprintRows(CSVFILE* file_ptr);

// Adds a new row to the CSV file struct
void CSVFaddRow(CSVFILE* file_ptr, char** row, int row_size);

// Inserts a new row to the CSV file struct at a given index
void CSVFinsertRow(CSVFILE* file_ptr, char** row, int row_size, int row_index);

// Reads the data from the filename of the current CSV file struct if exists and stores them in memory
void CSVFreadRows(CSVFILE* file_ptr);

// Prints the row-sizes list
void CSVFprintRowsSizes(CSVFILE* file_ptr);

// Save a CSV file struct
void CSVFsaveRows(CSVFILE* file_ptr);

// Delete a row with a given index
void CSVFdelRow(CSVFILE* file_ptr, int row_index);

// Free the current CSV file struct from the heap
void CSVFfreeMem(CSVFILE* file_ptr);

#endif