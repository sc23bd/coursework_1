#include "utils.h"

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
