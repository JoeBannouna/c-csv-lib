#ifndef VECTOR_STRUCT_INCLUDE
#define VECTOR_STRUCT_INCLUDE

#include <stdlib.h>
#include <stdbool.h>

typedef struct CharVec {
  int length;
  int current_max_size;
  char* ptr;
} CharVec;

CharVec* initCharVec(int length);

int getStringLength(CharVec* vec_ptr);

bool addChar(CharVec* vec_ptr, char ch);

bool freeCharVec(CharVec* vec_ptr);

#endif