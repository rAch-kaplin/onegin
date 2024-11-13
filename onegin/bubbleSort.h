#ifndef _HBUBBLE_SORT
#define _HBUBBLE_SORT

#include "read_file.h"
#include "comparator.h"

void swap(StringElement *str1, StringElement *str2);
void bubbleSort(const FileData *file_data, int (*sort)(const StringElement *, const StringElement *));

#endif
