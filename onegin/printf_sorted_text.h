#ifndef _HPRINTF_SORTED_TEXT
#define _HPRINTF_SORTED_TEXT

#include "read_file.h"

// typedef struct
// {
//     char **lines;
//     size_t SIZE;
// } FileData;

void oneginSortedFileFromLeft(const FileData *file_data);
void printfSortedText(const FileData *file_data);
void oneginSortedFileFromRight(const FileData *file_data);
void printfSortedTextFromRight(const FileData *file_data);

#endif
