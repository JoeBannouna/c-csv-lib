#include <time.h>

#include "csvfile.h"

// Takes in the full length of char including null terminator, output is a
// (length - 1) long random string
char* generateRandomString(int length, char* string) {
  for (int i = 0; i < length - 1; i++) {
    int randInt = rand() % 26;
    string[i] = 'a' + randInt;
  }

  string[length - 1] = '\0';
}

int main() {
  srand(time(NULL));

  CSVFILE* seeding_data_ptr = CSVFinit("test");

  // for (int i = 0; i < 100; i++) {
  //   char test_string[10];
  //   generateRandomString(10, test_string);

  //   char* row[] = {test_string};
  //   CSVFaddRow(seeding_data_ptr, row, 1);
  // }

  // CSVFsaveRows(seeding_data_ptr);

  // CSVFfreeMem(seeding_data_ptr);

  CSVFreadRows(seeding_data_ptr);

  char* test_row[] = {"something", "lol", "hamada"};
  CSVFaddRow(seeding_data_ptr, test_row, 3);
  CSVFprintRows(seeding_data_ptr);
}