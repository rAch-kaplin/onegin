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

    char *file_content = NULL;
    FileData file_data = {};

    codeError error = readFile(&file_content, &file_data);

    if (error != NO_ERROR)
    {
        switch (error)
        {
            case NO_ERROR:
                break;
            case FAILED_OPEN_FILE: fprintf(stderr, "Failed open file\n");
                break;
            case MEMORY_ALLOCATION_ERROR: fprintf(stderr, "MEMORY_ALLOCATION_ERROR\n");
                break;
            case FILE_READ_ERROR: fprintf(stderr, "FILE_READ_ERROR\n");
                break;
            default:
                fprintf(stderr, "Unknow error occurred\n");
        }

    }

    // fileDataCtor
    // ctor, constructor
    // dtor, destructor


    bubbleSort(&file_data, myStrcmpFromRight);
    oneginSortedFileFromRight(&file_data);
    printfSortedTextFromRight(&file_data);

    bubbleSort(&file_data, mySrtcmpFromLeft);
    oneginSortedFileFromLeft(&file_data);
    printfSortedText(&file_data);

    resultOfReadFile(&file_data);

    free(file_content);
    free(file_data.lines);

    return 0;
}
