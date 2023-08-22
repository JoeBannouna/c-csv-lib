#include "csvfile.h"

int main() {
  CSVFILE* test_file_ptr = initCSVFILE("test1");

  char* row1[] = {"hello", "lol"};
  char* row2[] = {"omg", "o", "WOW"};
  char* row3[] = {"holy"};

  addRow(test_file_ptr, row1, 2);
  addRow(test_file_ptr, row2, 3);
  addRow(test_file_ptr, row3, 1);

  printRows(test_file_ptr);
  saveRows(test_file_ptr);
}