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

  // for (int j = 0; j < i; j++) {
  //   printf("Date: %s\n", records[j].date);
  //   printf("Time: %s\n", records[j].time);
  //   printf("Steps: %s\n", records[j].steps);
  // }

  printf("Number of records in file: %d\n", i);
  for (int a = 0; a < 3; a++) {
    printf("%s/%s/%s\n", records[a].date, records[a].time, records[a].steps);
  }

  fclose(file);
  return EXIT_SUCCESS;
}
