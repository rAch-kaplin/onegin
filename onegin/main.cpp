#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "read_file.h"
#include "comparator.h"
#include "bubbleSort.h"
#include "printf_sorted_text.h"

int main()
{
    size_t SIZE = 0;
    size_t row_count = 10;

    char **str = (char**)calloc(row_count, sizeof(char*));
    assert(str != NULL);

    readFile(&str, &SIZE, &row_count);

    resultOfReadFile(str, SIZE);

    bubbleSort(str, SIZE, myStrcmpFromRight);
    oneginSortedFileFromRight(str, SIZE);
    printfSortedTextFromRight(str, SIZE);

    bubbleSort(str, SIZE, mySrtcmpFromLeft);
    oneginSortedFileFromLeft(str, SIZE);
    printfSortedText(str, SIZE);

    return 0;
}









