#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void readFile(char ***str, size_t *SIZE);
void resultOfReadFile(char **str, size_t SIZE);
int mySrtcmpFromLeft(const char *pstr1, const char *pstr2);
void bubbleSort(char **str, size_t size, int (*sort)(const char *, const char *));
void oneginSortedFileFromLeft(char **str, size_t SIZE);
void printfSortedText(char **str, size_t SIZE);

void oneginSortedFileFromRight(char **str, size_t SIZE);
int myStrcmpFromRight(const char *pstr1, const char *pstr2);
void printfSortedTextFromRight(char **str, size_t SIZE);


int main()
{
    size_t SIZE = 0;
    //size_t row_count = 10;

    char **str = NULL;
    //assert(str != NULL);

    readFile(&str, &SIZE);

    resultOfReadFile(str, SIZE);

    bubbleSort(str, SIZE, myStrcmpFromRight);
    oneginSortedFileFromRight(str, SIZE);
    printfSortedTextFromRight(str, SIZE);

    bubbleSort(str, SIZE, mySrtcmpFromLeft);
    oneginSortedFileFromLeft(str, SIZE);
    printfSortedText(str, SIZE);

    free(str[0]);
    free(str);

    return 0;
}

void readFile(char ***str, size_t *SIZE)
{
    FILE * file = fopen("onegin.txt", "r");
    assert(file != NULL);

    fseek(file, 0, SEEK_END);
    size_t size_of_file = (size_t)ftell(file);
    fseek(file, 0, SEEK_SET);
    printf("---SIZE_OF_FILE = %zu\n", size_of_file);

    char * file_content = (char*)calloc(size_of_file + 1, sizeof(char));
    assert(file_content != NULL);

    fread(file_content, sizeof(char), size_of_file, file);
    fclose(file);

    for (size_t i = 0; i < size_of_file; i++)
    {
        if (file_content[i] == '\n')
        {
            file_content[i] = '\0';
            (*SIZE)++;
        }
    }


    printf("nStrings = %zu\n", *SIZE);

    *str = (char**)calloc(*SIZE + 1, sizeof(char*));
    assert(*str != NULL);

    size_t line_index = 0;
    (*str)[line_index++] = file_content;
    for (size_t i = 0; i < size_of_file; i++)
    {
        if (file_content[i] == '\0' && i + 1 < size_of_file)
            (*str)[line_index++] = &file_content[i + 1];
    }
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

void bubbleSort(char **str, size_t SIZE, int (*sort)(const char *, const char *))
{
    for (size_t i = 0; i < SIZE - 1; i++)
    {
        for (size_t j = 0; j < SIZE - i - 1; j++)
        {
            int res = sort(str[j], str[j + 1]);
            if (res > 0)
            {
                char* buffer = str[j];
                str[j] = str[j + 1];
                str[j + 1] = buffer;
            }
        }
    }
}

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
    }
}
