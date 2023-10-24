#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FITNESS_DATA records[512];
  FILE *file = openFile("../static/data.csv", "r");

  char line_buffer[512];
  int i = 0;
  while (fgets(line_buffer, sizeof(line_buffer), file)) {
    tokeniseRecordModified(line_buffer, ",", &records[i]);
    i++;
  }

  for (int j = 0; j < i; j++) {
    printf("Date: %s\n", records[j].date);
    printf("Time: %s\n", records[j].time);
    printf("Steps: %s\n", records[j].steps);
  }

  // tokeniseRecordModified("2020-01-01,12:00,1000", ",", &records);
  //
  // printf("Date: %s\n", records.date);
  // printf("Time: %s\n", records.time);
  // printf("Steps: %s\n", records.steps);

  fclose(file);
  return EXIT_SUCCESS;
}
