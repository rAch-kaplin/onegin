#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct
{
    char **lines;
    size_t SIZE;
} FileData;

void readFile(char **file_content, FileData *file_data);
void resultOfReadFile(const FileData *file_data);
int mySrtcmpFromLeft(const char *pstr1, const char *pstr2);
void bubbleSort(const FileData *file_data, int (*sort)(const char *, const char *));
void oneginSortedFileFromLeft(const FileData *file_data);
void printfSortedText(const FileData *file_data);
void swap(char ** str1, char **str2);

void oneginSortedFileFromRight(const FileData *file_data);
int myStrcmpFromRight(const char *pstr1, const char *pstr2);
void printfSortedTextFromRight(const FileData *file_data);


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


int mySrtcmpFromLeft(const char *pstr1, const char *pstr2)
{
    int i = 0, j = 0;

    while (pstr1[i] != '\0')
    {
        while (pstr1[i] != '\0' && !isalnum((unsigned char)pstr1[i]))
            i++;
        while (pstr2[j] != '\0' && !isalnum((unsigned char)pstr2[j]))
            j++;

        char ch1 = (char)tolower((unsigned char)pstr1[i]);
        char ch2 = (char)tolower((unsigned char)pstr2[j]);

        if (ch1 != ch2)
            break;

        i++;
        j++;
    }

    return pstr1[i] - pstr2[j];
}

int myStrcmpFromRight(const char *pstr1, const char *pstr2)
{
    size_t i = strlen(pstr1) - 1, j = strlen(pstr2) - 1;

    while (1)
    {
        while (!isalnum((unsigned char)pstr1[i]))
        {
            i--;
            //fprintf(stderr, "i = %zu ", i);
        }

        while (!isalnum((unsigned char)pstr2[j]))
        {
            j--;
            //fprintf(stderr, "j = %zu ", j);
        }

        if (i == 0 && j == 0)
            break;

        if ((i == 0 && j != 0) || (j == 0 && i != 0))
            break;

        char ch1 = (char)tolower((unsigned char)pstr1[i]);
        char ch2 = (char)tolower((unsigned char)pstr2[j]);

        if (ch1 != ch2)
            break;

        i--;
        j--;
    }

    return pstr1[i] - pstr2[j];
}

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

void oneginSortedFileFromLeft(const FileData *file_data)
{
    FILE *fp = fopen("onegin_sorted_from_left.txt", "w");
    assert(fp != NULL);
    for (size_t j = 0; j < file_data->SIZE; j++)
    {
        fprintf(fp, "%s\n", file_data->lines[j]);
    }
    fclose(fp);
}

void oneginSortedFileFromRight(const FileData *file_data)
{
    FILE *fp = fopen("onegin_sorted_from_right.txt", "w");
    assert(fp != NULL);
    for (size_t j = 0; j < file_data->SIZE; j++)
    {
        fprintf(fp, "%s\n", file_data->lines[j]);
    }
    fclose(fp);
}

void printfSortedTextFromRight(const FileData *file_data)
{
    puts("Отсортированный текст from right:\n");
    for (size_t j = 0; j < file_data->SIZE; j++)
    {
        printf("%s\n", file_data->lines[j]);
    }
    putchar('\n');
}

void printfSortedText(const FileData *file_data)
{
    puts("Отсортированный текст from left:\n");
    for (size_t j = 0; j < file_data->SIZE; j++)
    {
        printf("%s\n", file_data->lines[j]);
    }
}
