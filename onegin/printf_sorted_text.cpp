#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "printf_sorted_text.h"


void oneginSortedFileFromLeft(char **str, size_t SIZE)
{
    FILE *fp = fopen("onegin_sorted_from_left.txt", "w");
    assert(fp != NULL);
    for (size_t j = 0; j < SIZE; j++)
    {
        fprintf(fp, "%s\n", str[j]);
    }
    fclose(fp);
}

void oneginSortedFileFromRight(char **str, size_t SIZE)
{
    FILE *fp = fopen("onegin_sorted_from_right.txt", "w");
    assert(fp != NULL);
    for (size_t j = 0; j < SIZE; j++)
    {
        fprintf(fp, "%s\n", str[j]);
    }
    fclose(fp);
}

void printfSortedTextFromRight(char **str, size_t SIZE)
{
    puts("Отсортированный текст from right:\n");
    for (size_t j = 0; j < SIZE; j++)
    {
        printf("%s\n", str[j]);
    }
    putchar('\n');
}

void printfSortedText(char **str, size_t SIZE)
{
    puts("Отсортированный текст from left:\n");
    for (size_t j = 0; j < SIZE; j++)
    {
        printf("%s\n", str[j]);
        free(str[j]);
    }
    free(str);
}
