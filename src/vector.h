#ifndef VECTOR_STRUCT_INCLUDE
#define VECTOR_STRUCT_INCLUDE

#include <stdlib.h>
#include <stdbool.h>

typedef struct CharVec {
  int length;
  int current_max_size;
  char* ptr;
} CharVec;

CharVec* charVecInit(int length);

int charVecGetStringLength(CharVec* vec_ptr);

bool charVecAddChar(CharVec* vec_ptr, char ch);

bool charVecFreeCharVec(CharVec* vec_ptr);

#endif