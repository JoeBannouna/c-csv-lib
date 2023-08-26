#include "vector.h"

CharVec* initCharVec(int length) {
  CharVec* vec_ptr = malloc(sizeof(CharVec));
  vec_ptr->length = 1;
  vec_ptr->current_max_size = 1;

  vec_ptr->ptr = NULL;
  // vec_ptr->ptr = malloc(sizeof(char) * vec_ptr->current_max_size);

  // vec_ptr->ptr[length - 1] = '\0';
}

int getStringLength(CharVec* vec_ptr) { return vec_ptr->length - 1; }

bool addChar(CharVec* vec_ptr, char ch) {
  if (vec_ptr->length == vec_ptr->current_max_size) {
    vec_ptr->current_max_size *= 2;

    vec_ptr->ptr =
        realloc(vec_ptr->ptr, sizeof(char) * vec_ptr->current_max_size);

    if (vec_ptr == NULL) {
      return false;
    }
  }

  vec_ptr->length += 1;
  // printf("length %d\n", vec_ptr->length);
  vec_ptr->ptr[vec_ptr->length - 2] = ch;
  vec_ptr->ptr[vec_ptr->length - 1] = '\0';

  return true;
}

bool freeCharVec(CharVec* vec_ptr) {
  free(vec_ptr->ptr);
  free(vec_ptr);

  return true;
}