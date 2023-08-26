# C-CSV Library

Manage CSV files with ease in C.

### Quick start example
```c
#include "csvfile.h"

int main() {

  // Initialize a csv file struct
  // "test" is the name of the file that will be read or saved to
  CSVFILE* csv_file_ptr = CSVFinit("test");

  // The struct's data is stored in memory

  // Add rows through the following
  char* row1[] = {"apple", "orange"};
  char* row2[] = {"harry", "potter", "and", "the", "goblet"};
  char* row3[] = {"of", "fire"};

  CSVFaddRow(csv_file_ptr, row1, 2);
  CSVFaddRow(csv_file_ptr, row2, 3);
  CSVFaddRow(csv_file_ptr, row3, 1);

  // Delete a row
  CSVFdelRow(csv_file_ptr, 1);

  // Print the current CSV file stored in memory
  CSVFprintRows(csv_file_ptr);
  
  // Save the data to the file "test.csv"
  CSVFsaveRows(csv_file_ptr);



  // Initialize a new struct with the same filename
  CSVFILE* csv_file_ptr2 = CSVFinit("test");

  // Currently struct is empty
  // Read the file contents and store them in memory 
  CSVFreadRows(csv_file_ptr2);

  // Print the current CSV file stored in memory
  CSVFprintRows(csv_file_ptr);

  // Free the struct and its data from the heap
  CSVFfreeMem(csv_file_ptr);
}
```

### Available functions

Initializes a new CSVFile struct
```c
CSVFILE* CSVFinit(char* filename);
```

Prints rows of the CSV file struct
```c
void CSVFprintRows(CSVFILE* file_ptr);
```

Adds a new row to the end of CSV file object
```c
void CSVFaddRow(CSVFILE* file_ptr, char** row, int row_size);
```

Inserts a new row to the CSV file object at a given index
```c
void CSVFinsertRow(CSVFILE* file_ptr, char** row, int row_size, int row_index);
```

Reads the data from the filename of the current CSV file struct if exists and stores them in memory
```c
void CSVFreadRows(CSVFILE* file_ptr);
```

Save a CSV file object
```c
void CSVFsaveRows(CSVFILE* file_ptr);
```

Delete a row with a given index
```c
void CSVFdelRow(CSVFILE* file_ptr, int row_index);
```

Free the current CSV file struct from the heap
```c
void CSVFfreeMem(CSVFILE* file_ptr);
```