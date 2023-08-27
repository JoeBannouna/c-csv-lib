#include "csvfile.h"

#include "vector.h"

CSVFILE* csvfInit(char* filename) {
  CSVFILE* file = malloc(sizeof(CSVFILE));

  file->rows = NULL;
  file->rows_num = 0;
  file->rows_sizes = NULL;

  int filename_length = strnlen(filename, 100);
  file->filename = malloc(sizeof(char) * (filename_length + 5));
  strncpy(file->filename, filename, filename_length);
  // Add extension
  file->filename[filename_length + 4] = '\0';
  file->filename[filename_length + 3] = 'v';
  file->filename[filename_length + 2] = 's';
  file->filename[filename_length + 1] = 'c';
  file->filename[filename_length] = '.';

  return file;
}

void csvfAddRowSize(CSVFILE* file_ptr, int size) {
  int* temp_sizes = file_ptr->rows_sizes;
  file_ptr->rows_sizes = malloc(sizeof(int) * file_ptr->rows_num);

  if (temp_sizes != NULL) {
    for (int i = 0; i < file_ptr->rows_num - 1; i++) {
      file_ptr->rows_sizes[i] = temp_sizes[i];
    }

    free(temp_sizes);
  }

  file_ptr->rows_sizes[file_ptr->rows_num - 1] = size;
}

void csvfInsertRowSize(CSVFILE* file_ptr, int size, int row_index) {
  int* temp_sizes = file_ptr->rows_sizes;
  file_ptr->rows_sizes = malloc(sizeof(int) * file_ptr->rows_num);

  if (temp_sizes != NULL) {
    int skipped = 0;

    for (int i = 0; i < file_ptr->rows_num - 1; i++) {
      if (i == row_index) skipped = 1;
      file_ptr->rows_sizes[i + skipped] = temp_sizes[i];
    }

    free(temp_sizes);
  }

  file_ptr->rows_sizes[row_index] = size;
}

void csvfDelRowSize(CSVFILE* file_ptr, int index) {
  int* temp_sizes = file_ptr->rows_sizes;
  file_ptr->rows_sizes = malloc(sizeof(int) * file_ptr->rows_num);

  int skipped = 0;

  if (temp_sizes != NULL) {
    for (int i = 0; i < file_ptr->rows_num + 1; i++) {
      if (i == index)
        skipped = 1;
      else
        file_ptr->rows_sizes[i - skipped] = temp_sizes[i];
    }

    free(temp_sizes);
  }
}

void csvfPrintRowsSizes(CSVFILE* file_ptr) {
  for (int i = 0; i < file_ptr->rows_num; i++) {
    printf("%d\n", file_ptr->rows_sizes[i]);
  }
}

void csvfAddRow(CSVFILE* file_ptr, char** row, int row_size) {
  file_ptr->rows_num += 1;

  // Make new row
  char** new_row = malloc(sizeof(char*) * row_size);

  for (int i = 0; i < row_size; i++) {
    char* word = row[i];
    int word_length = strnlen(word, MAX_COL_SIZE);

    new_row[i] = malloc(sizeof(char) * (word_length + 1));
    strncpy(new_row[i], word, word_length + 1);
  }

  // Make space for new row
  char*** temp_rows = file_ptr->rows;
  file_ptr->rows = malloc(sizeof(char**) * file_ptr->rows_num);

  if (temp_rows != NULL) {
    // Copy content to new malloc pointer
    for (int i = 0; i < file_ptr->rows_num; i++) {
      file_ptr->rows[i] = temp_rows[i];
    }

    free(temp_rows);
  }

  // Add the new row
  file_ptr->rows[file_ptr->rows_num - 1] = new_row;
  csvfAddRowSize(file_ptr, row_size);
}

void csvfInsertRow(CSVFILE* file_ptr, char** row, int row_size, int row_index) {
  // Check that the index isn't too high
  if (row_index > file_ptr->rows_num) {
    printf("Error: INDEX OF ROW TO INSERT IS TOO HIGH\n");
    return;
  }

  // Add extra row to rows_num for the row to be inserted
  file_ptr->rows_num += 1;

  // Make new row
  char** new_row = malloc(sizeof(char*) * row_size);

  for (int i = 0; i < row_size; i++) {
    char* word = row[i];
    int word_length = strnlen(word, MAX_COL_SIZE);

    new_row[i] = malloc(sizeof(char) * (word_length + 1));
    strncpy(new_row[i], word, word_length);
  }

  // Make space for new row
  char*** temp_rows = file_ptr->rows;
  file_ptr->rows = malloc(sizeof(char**) * file_ptr->rows_num);

  if (temp_rows != NULL) {
    int skipped = 0;

    // Copy content to new malloc pointer
    for (int i = 0; i < file_ptr->rows_num; i++) {
      if (i == row_index) skipped = 1;
      file_ptr->rows[i + skipped] = temp_rows[i];
    }

    free(temp_rows);
  }

  // Add the new row
  file_ptr->rows[row_index] = new_row;
  csvfInsertRowSize(file_ptr, row_size, row_index);
}

void csvfReadRows(CSVFILE* file_ptr) {
  FILE* file = fopen(file_ptr->filename, "r");

  if (file != NULL) {
    char ch = 0;

    int current_row_size = 1;
    char** current_row = malloc(sizeof(char*) * current_row_size);

    CharVec* current_word = charVecInit(1);
    // printf("length is %d\n", current_word->length);

    while (!feof(file)) {
      ch = fgetc(file);

      if (ch == ',') {
        // Next word
        if (charVecGetStringLength(current_word) != 0) {
          current_row[current_row_size - 1] = current_word->ptr;

          free(current_word);
          current_word = charVecInit(1);

          current_row_size++;
          current_row = realloc(current_row, sizeof(char*) * current_row_size);
        }
      } else if (ch == '\n') {
        // New line
        if (charVecGetStringLength(current_word) != 0) {
          current_row[current_row_size - 1] = current_word->ptr;
          free(current_word);
          current_word = charVecInit(1);
        } else {
          current_row_size--;

          current_row = realloc(current_row, sizeof(char*) * current_row_size);
        }

        csvfAddRow(file_ptr, current_row, current_row_size);

        // Free dangling memory
        for (int i = 0; i < current_row_size; i++) {
          free(current_row[i]);
        }
        free(current_row);

        current_row_size = 1;
        current_row = malloc(sizeof(char*) * current_row_size);
      } else {
        // Normal character
        charVecAddChar(current_word, ch);
      }
    }

    charVecFreeCharVec(current_word);

    fclose(file);
  } else {
    printf("Could not open file.\n");
  }
}

void csvfPrintRows(CSVFILE* file_ptr) {
  for (int i = 0; i < file_ptr->rows_num; i++) {
    for (int k = 0; k < file_ptr->rows_sizes[i]; k++) {
      printf("%s", file_ptr->rows[i][k]);
      if (k != file_ptr->rows_sizes[i] - 1) printf(",");
    }

    printf("\n");
  }
}

void csvfSaveRows(CSVFILE* file_ptr) {
  FILE* file = fopen(file_ptr->filename, "w");

  if (file != NULL) {
    for (int i = 0; i < file_ptr->rows_num; i++) {
      for (int k = 0; k < file_ptr->rows_sizes[i]; k++) {
        fprintf(file, "%s", file_ptr->rows[i][k]);
        if (k != file_ptr->rows_sizes[i] - 1) fprintf(file, ",");
      }

      fprintf(file, "\n");
    }

    fclose(file);
  } else {
    printf("Could not open file.\n");
  }
}

void csvfDelRow(CSVFILE* file_ptr, int row_index) {
  int row_words_num = file_ptr->rows_sizes[row_index];

  file_ptr->rows_num -= 1;

  for (int i = 0; i < row_words_num; i++) {
    free(file_ptr->rows[row_index][i]);
  }

  csvfDelRowSize(file_ptr, row_index);

  free(file_ptr->rows[row_index]);

  // Make space for new row
  char*** temp_rows = file_ptr->rows;
  file_ptr->rows = malloc(sizeof(char**) * file_ptr->rows_num);

  if (temp_rows != NULL) {
    int skipped = 0;

    // Copy content to new malloc pointer
    for (int i = 0; i < file_ptr->rows_num + 1; i++) {
      if (i == row_index)
        skipped = 1;
      else
        file_ptr->rows[i - skipped] = temp_rows[i];
    }

    free(temp_rows);
  }
}

void csvfFreeMem(CSVFILE* file_ptr) {
  // Free & delete filename
  free(file_ptr->filename);

  // Free & delete all rows
  for (int i = file_ptr->rows_num - 1; i >= 0; i--) {
    csvfDelRow(file_ptr, i);
  }

  free(file_ptr->rows);
  free(file_ptr->rows_sizes);

  free(file_ptr);
}