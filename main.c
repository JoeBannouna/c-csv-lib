#include "src/csvfile.h"

int main() {
  CSVFILE* seeding_data_ptr = csvfInit("test");

  // for (int i = 0; i < 100; i++) {
  //   char test_string[10];
  //   generateRandomString(10, test_string);

  //   char* row[] = {test_string};
  //   csvfAddRow(seeding_data_ptr, row, 1);
  // }

  // csvfSaveRows(seeding_data_ptr);

  // csvfFreeMem(seeding_data_ptr);

  csvfReadRows(seeding_data_ptr);

  char* test_row[] = {"test1", "test2", "test3"};
  csvfAddRow(seeding_data_ptr, test_row, 3);
  csvfPrintRows(seeding_data_ptr);
}