#include <stddef.h>
#include "bubbleSort.h"

void swap(char ** str1, char **str2)
{
    char *buffer = *str1;
    *str1 = *str2;
    *str2 = buffer;
}

void bubbleSort(const FileData *file_data, int (*sort)(const char *, const char *))
{
    for (size_t i = 0; i < file_data->SIZE - 1; i++)
    {
        for (size_t j = 0; j < file_data->SIZE - i - 1; j++)
        {
            int res = sort(file_data->lines[j], file_data->lines[j + 1]);
            if (res > 0)
            {
                swap(&(file_data->lines)[j], &(file_data->lines)[j + 1]);
            }
        }
    }
}
