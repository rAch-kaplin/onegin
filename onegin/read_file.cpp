#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "read_file.h"


void readFile(char ***str, size_t *SIZE, size_t *row_count)
{
    FILE * file = fopen("onegin.txt", "r");
    assert(file != NULL);

    const size_t MAX_LENGHT_STRING = 100;
    char buffer[MAX_LENGHT_STRING] = {};

    while (fgets(buffer, MAX_LENGHT_STRING, file) != NULL)
    {
        size_t len = strlen(buffer);
        //printf("strlen(buffer = %zu)\n", len);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';

        //printf("Прочитанная строка: %s\n", buffer);

        (*str)[*SIZE] = (char*)calloc((len + 1), sizeof(char));
        assert(*str != NULL);
        strcpy((*str)[*SIZE], buffer);
        (*SIZE)++;

        if (*SIZE >= *row_count)
        {
            *row_count *= 2;
            *str = (char**)realloc(*str, *row_count * sizeof(char*));
            assert(*str != NULL);
        }
    }
    fclose(file);
}

void resultOfReadFile(char **str, size_t SIZE)
{
    printf("SIZE = <<%zu>>\n\n", SIZE);
    puts("Содержимое считанного файла:\n");
    for (size_t j = 0; j < SIZE; j++)
    {
        printf("---%s\n", str[j]);
    }
    putchar('\n');
}
