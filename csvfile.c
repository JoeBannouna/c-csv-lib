#include "csvfile.h"

CSVFILE* initCSVFILE(char* filename) {
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

void addRowSize(CSVFILE* file_ptr, int size) {
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

void addRow(CSVFILE* file_ptr, char** row, int row_size) {
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
    // Copy content to new malloc pointer
    for (int i = 0; i < file_ptr->rows_num; i++) {
      file_ptr->rows[i] = temp_rows[i];
    }

    free(temp_rows);
  }

  // Add the new row
  file_ptr->rows[file_ptr->rows_num - 1] = new_row;
  addRowSize(file_ptr, row_size);
}

void printRows(CSVFILE* file_ptr) {
  for (int i = 0; i < file_ptr->rows_num; i++) {
    for (int k = 0; k < file_ptr->rows_sizes[i]; k++) {
      printf("%s", file_ptr->rows[i][k]);
      if (k != file_ptr->rows_sizes[i] - 1) printf(",");
    }

    printf("\n");
  }
}

void saveRows(CSVFILE* file_ptr) {
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