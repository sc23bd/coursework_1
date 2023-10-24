#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char date[11];
  char time[6];
  char steps[10];
} FITNESS_DATA;

void tokeniseRecordModified(char *input, const char *delimeter,
                            FITNESS_DATA *record);

#endif // !UTILS_H
