#ifndef _HBUBBLE_SORT
#define _HBUBBLE_SORT

#include "read_file.h"
#include "comparator.h"


void swap(char ** str1, char **str2);
void bubbleSort(const FileData *file_data, int (*sort)(const char *, const char *));
// int mySrtcmpFromLeft(const char *pstr1, const char *pstr2);
// int myStrcmpFromRight(const char *pstr1, const char *pstr2);

#endif
