#ifndef _HREAD_FILE
#define _HREAD_FILE
#include <stdio.h>
#include "comparator.h"

typedef struct
{
    StringElement *lines;
    size_t size;    
} FileData;

enum codeError
{
    FAILED_OPEN_FILE = 1,
    MEMORY_ALLOCATION_ERROR = 10,
    FILE_READ_ERROR = 100,
    NO_ERROR = 0
};

void fileSize(FILE *file, size_t *size_of_file);
codeError readFile(char **file_content, FileData *file_data);
void resultOfReadFile(const FileData *file_data);

#endif
