#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "read_file.h"
#include "comparator.h"
#include "bubbleSort.h"
#include "printf_sorted_text.h"

// typedef struct
// {
//     char **lines;
//     size_t SIZE;
// } FileData;

int main()
{
    //size_t SIZE = 0;

    char *file_content = NULL;
    FileData file_data = {0};

    readFile(&file_content, &file_data);

    resultOfReadFile(&file_data);

    bubbleSort(&file_data, myStrcmpFromRight);
    oneginSortedFileFromRight(&file_data);
    printfSortedTextFromRight(&file_data);

    bubbleSort(&file_data, mySrtcmpFromLeft);
    oneginSortedFileFromLeft(&file_data);
    printfSortedText(&file_data);

    free(file_content);
    free(file_data.lines);

    return 0;
}









