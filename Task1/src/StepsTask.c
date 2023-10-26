#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char date[11];
  char time[6];
  char steps[10];
} FITNESS_DATA;

// modified to take in a pointer to record struct rather
// than the individual fields
void tokeniseRecordModified(char *input, const char *delimeter,
                            FITNESS_DATA *record) {
  char *inputCopy = strdup(input);
  char *token = strtok(inputCopy, delimeter);

  if (token == NULL) {
    perror("Invalid input");
    return;
  } else {
    strcpy(record->date, token);
  }

  token = strtok(NULL, delimeter);
  if (token == NULL) {
    perror("Invalid input");
    return;
  } else {
    strcpy(record->time, token);
  }

  token = strtok(NULL, delimeter);
  if (token == NULL) {
    perror("Invalid input");
    return;
  } else {
    strcpy(record->steps, token);
  }

  free(inputCopy);
}

FILE *openFile(char filename[], char mode[]) {
  FILE *file = fopen(filename, mode);
  if (file == NULL) {
    perror("");
    exit(EXIT_FAILURE);
  }
  return file;
}

int main(int argc, char *argv[]) {
  FITNESS_DATA records[512];
  FILE *file = openFile("FitnessData_2023.csv", "r");

  char line_buffer[512];
  int i = 0;
  while (fgets(line_buffer, sizeof(line_buffer), file)) {
    tokeniseRecordModified(line_buffer, ",", &records[i]);
    i++;
  }

  // for (int j = 0; j < i; j++) {
  //   printf("Date: %s\n", records[j].date);
  //   printf("Time: %s\n", records[j].time);
  //   printf("Steps: %s\n", records[j].steps);
  // }

  printf("Number of records in file: %d\n", i);
  for (int a = 0; a < 3; a++) {
    printf("%s/%s/%s", records[a].date, records[a].time, records[a].steps);
  }

  fclose(file);
  return EXIT_SUCCESS;
}
