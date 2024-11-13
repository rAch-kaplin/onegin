#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "printf_sorted_text.h"


void oneginSortedFileFromLeft(const FileData *file_data)
{
    FILE *fp = fopen("onegin_sorted_from_left.txt", "w");
    assert(fp != NULL);
    for (size_t j = 0; j < file_data->size; j++)
    {
        fprintf(fp, "%s\n", file_data->lines[j].str);
    }
    fclose(fp);
}

void oneginSortedFileFromRight(const FileData *file_data)
{
    FILE *fp = fopen("onegin_sorted_from_right.txt", "w");
    assert(fp != NULL);
    for (size_t j = 0; j < file_data->size; j++)
    {
        fprintf(fp, "%s\n", file_data->lines[j].str);
    }
    fclose(fp);
}

void printfSortedTextFromRight(const FileData *file_data)
{
    puts("Отсортированный текст from right:\n");
    for (size_t j = 0; j < file_data->size; j++)
    {
        printf("%s\n", file_data->lines[j].str);
    }
    putchar('\n');
}

void printfSortedText(const FileData *file_data)
{
    puts("Отсортированный текст from left:\n");
    for (size_t j = 0; j < file_data->size; j++)
    {
        printf("%s\n", file_data->lines[j].str);
    }
}
