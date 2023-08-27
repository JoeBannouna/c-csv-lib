#include "utils.h"

char* generateRandomString(int length, char* string) {
  for (int i = 0; i < length - 1; i++) {
    int randInt = rand() % 26;
    string[i] = 'a' + randInt;
  }

  string[length - 1] = '\0';
}