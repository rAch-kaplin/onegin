#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "read_file.h"

void fileSize(FILE *file, size_t *size_of_file)
{

    long current_position = ftell(file);
    fseek(file, 0, SEEK_END); //kernigan invariant file
    *size_of_file = (size_t)ftell(file);
    fseek(file, current_position, SEEK_SET);
}

void readFile(char **file_content, FileData *file_data)
{
    FILE * file = fopen("onegin.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open file\n");
        //return -1;
    }

    size_t size_of_file = 0;
    fileSize(file, &size_of_file);

    printf("---SIZE_OF_FILE = %zu\n", size_of_file);

    *file_content = (char*)calloc(size_of_file + 1, sizeof(char));
    if (*file_content == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        //return -2;
    }

    if (fread(*file_content, sizeof(char), size_of_file, file) != size_of_file)
    {
        fprintf(stderr, "File read error\n");
        //return -3;
    }
    fclose(file);

    for (size_t i = 0; i < size_of_file; i++)
    {
        if ((*file_content)[i] == '\n')
        {
            (*file_content)[i] = '\0';
            file_data->size++;
        }
    }


    printf("nStrings = %zu\n", file_data->size);

    file_data->lines = (char**)calloc(file_data->size + 1, sizeof(char*));
    assert(file_data->lines != NULL);

    size_t line_index = 0;
    (file_data->lines)[line_index++] = *file_content;
    for (size_t i = 0; i < size_of_file; i++) // strchr
    {
        if ((*file_content)[i] == '\0' && i + 1 < size_of_file)
            (file_data->lines)[line_index++] = &(*file_content)[i + 1];
    }
}

void resultOfReadFile(const FileData *file_data)
{
    printf("size = <<%zu>>\n\n", file_data->size);
    puts("Содержимое считанного файла:\n");
    for (size_t j = 0; j < file_data->size; j++)
    {
        printf("---%s\n", file_data->lines[j]);
    }
    putchar('\n');
}
