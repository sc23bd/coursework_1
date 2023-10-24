#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char date[11];
  char time[6];
  char steps[6];
} FITNESS_DATA;

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

int main(int argc, char *argv[]) {
  FITNESS_DATA records;

  tokeniseRecordModified("2020-01-01,12:00,1000", ",", &records);

  printf("Date: %s\n", records.date);
  printf("Time: %s\n", records.time);
  printf("Steps: %s\n", records.steps);

  return EXIT_SUCCESS;
}
