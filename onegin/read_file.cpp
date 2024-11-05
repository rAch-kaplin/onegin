#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "read_file.h"


void readFile(char **file_content, FileData *file_data)
{
    FILE * file = fopen("onegin.txt", "r");
    assert(file != NULL);

    fseek(file, 0, SEEK_END);
    size_t size_of_file = (size_t)ftell(file);
    fseek(file, 0, SEEK_SET);
    printf("---SIZE_OF_FILE = %zu\n", size_of_file);

    *file_content = (char*)calloc(size_of_file + 1, sizeof(char));
    assert(*file_content != NULL);

    if (fread(*file_content, sizeof(char), size_of_file, file) != size_of_file)
    {
        fputs("Error reading file", stderr);
        exit(3);
    }
    fclose(file);

    for (size_t i = 0; i < size_of_file; i++)
    {
        if ((*file_content)[i] == '\n')
        {
            (*file_content)[i] = '\0';
            file_data->SIZE++;
        }
    }


    printf("nStrings = %zu\n", file_data->SIZE);

    file_data->lines = (char**)calloc(file_data->SIZE + 1, sizeof(char*));
    assert(file_data->lines != NULL);

    size_t line_index = 0;
    (file_data->lines)[line_index++] = *file_content;
    for (size_t i = 0; i < size_of_file; i++)
    {
        if ((*file_content)[i] == '\0' && i + 1 < size_of_file)
            (file_data->lines)[line_index++] = &(*file_content)[i + 1];
    }
}

void resultOfReadFile(const FileData *file_data)
{
    printf("SIZE = <<%zu>>\n\n", file_data->SIZE);
    puts("Содержимое считанного файла:\n");
    for (size_t j = 0; j < file_data->SIZE; j++)
    {
        printf("---%s\n", file_data->lines[j]);
    }
    putchar('\n');
}
