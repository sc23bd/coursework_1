#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FITNESS_DATA records;

  tokeniseRecordModified("2020-01-01,12:00,1000", ",", &records);

  printf("Date: %s\n", records.date);
  printf("Time: %s\n", records.time);
  printf("Steps: %s\n", records.steps);

  return EXIT_SUCCESS;
}
