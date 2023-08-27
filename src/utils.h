#ifndef UTILS_INCLUDE
#define UTILS_INCLUDE

#include <stdlib.h>
#include <time.h>

// Takes in the full length of char including null terminator, output is a
// (length - 1) long random string
char* generateRandomString(int length, char* string);

#endif