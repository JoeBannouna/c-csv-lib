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
CSVFILE* csvfInit(char* filename);

// Adds a row-size to the list that tracks row-sizes in memory
void csvfAddRowSize(CSVFILE* file_ptr, int size);

// Inserts a row-size at a certain index
void csvfInsertRowSize(CSVFILE* file_ptr, int size, int row_index);

// Deletes a row-size at a certain index
void csvfDelRowSize(CSVFILE* file_ptr, int index);

// Prints rows of the CSV file struct
void csvfPrintRows(CSVFILE* file_ptr);

// Adds a new row to the CSV file struct
void csvfAddRow(CSVFILE* file_ptr, char** row, int row_size);

// Inserts a new row to the CSV file struct at a given index
void csvfInsertRow(CSVFILE* file_ptr, char** row, int row_size, int row_index);

// Reads the data from the filename of the current CSV file struct if exists and stores them in memory
void csvfReadRows(CSVFILE* file_ptr);

// Prints the row-sizes list
void csvfPrintRowsSizes(CSVFILE* file_ptr);

// Save a CSV file struct
void csvfSaveRows(CSVFILE* file_ptr);

// Delete a row with a given index
void csvfDelRow(CSVFILE* file_ptr, int row_index);

// Free the current CSV file struct from the heap
void csvfFreeMem(CSVFILE* file_ptr);

#endif