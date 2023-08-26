#ifndef VECTOR_STRUCT_INCLUDE
#define VECTOR_STRUCT_INCLUDE

#include <stdlib.h>
#include <stdbool.h>

typedef struct CharVec {
  int length;
  int current_max_size;
  char* ptr;
} CharVec;

CharVec* CVinitCharVec(int length);

int CVgetStringLength(CharVec* vec_ptr);

bool CVaddChar(CharVec* vec_ptr, char ch);

bool CVfreeCharVec(CharVec* vec_ptr);

#endif