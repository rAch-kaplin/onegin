#ifndef _HREAD_FILE
#define _HREAD_FILE

typedef struct
{
    char **lines;
    size_t SIZE;
} FileData;

void readFile(char **file_content, FileData *file_data);
void resultOfReadFile(const FileData *file_data);

#endif
