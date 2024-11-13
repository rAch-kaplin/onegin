#include <stddef.h>
#include "bubbleSort.h"

void swap(StringElement *str1, StringElement *str2)
{
    StringElement buffer = *str1;
    *str1 = *str2;
    *str2 = buffer;
}

void bubbleSort(const FileData *file_data, int (*sort)(const StringElement *, const StringElement *)) //TODO: привести к прототипу qsort
{
    for (size_t i = 0; i < file_data->size - 1; i++)
    {
        for (size_t j = 0; j < file_data->size - i - 1; j++)
        {
            int res = sort(&file_data->lines[j], &file_data->lines[j + 1]);
            if (res > 0)
            {
                swap(&file_data->lines[j], &file_data->lines[j + 1]);
            }
        }
    }
}
