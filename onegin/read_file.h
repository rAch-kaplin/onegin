#ifndef _HREAD_FILE
#define _HREAD_FILE
#include <stdio.h>

typedef struct
{
    char **lines;
    size_t size;
} FileData;
void fileSize(FILE *file, size_t *size_of_file);
void readFile(char **file_content, FileData *file_data);
void resultOfReadFile(const FileData *file_data);

#endif
