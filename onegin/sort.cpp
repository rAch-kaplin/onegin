#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void readFile(char ***str, size_t *SIZE, size_t *row_count);
void resultOfReadFile(char **str, size_t SIZE);
int mySrtcmpFromLeft(const char *pstr1, const char *pstr2);
void bubbleSort(char **str, size_t size, int (*sort)(const char *, const char *));
void oneginSortedFile(char **str, size_t SIZE);
void printfSortedText(char **str, size_t SIZE);

void oneginSortedFileFromRight(char **str, size_t SIZE);
int myStrcmpFromRight(const char *pstr1, const char *pstr2);


int main()
{
    size_t SIZE = 0;
    size_t row_count = 10;

    char **str = (char**)calloc(row_count, sizeof(char*));
    assert(str != NULL);

    readFile(&str, &SIZE, &row_count);

    resultOfReadFile(str, SIZE);

    bubbleSort(str, SIZE, mySrtcmpFromLeft);
    bubbleSort(str, SIZE, myStrcmpFromRight);

    oneginSortedFile(str, SIZE);
    oneginSortedFileFromRight(str, SIZE);

    printfSortedText(str, SIZE);

    return 0;
}

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

    while (pstr1[i] != '\0')
    {
        while (pstr1[i] != '\0' && isalnum((unsigned char)pstr1[i]))
        {
            if (i == 0)
                break;
            i--;
            fprintf(stderr, "i = %zu ", i);
        }


        while (pstr2[j] != '\0' && isalnum((unsigned char)pstr2[j]))
        {
            if (j == 0)
                break;
            j--;
            fprintf(stderr, "j = %zu ", j);

        }

        char ch1 = (char)tolower((unsigned char)pstr1[i]);
        char ch2 = (char)tolower((unsigned char)pstr2[j]);

        if (ch1 != ch2)
            break;

        i--;
        j--;
    }

    return pstr1[i] - pstr2[j];
}

// void bubbleSort(char **str, size_t SIZE)
// {
//     for (size_t i = 0; i < SIZE - 1; i++)
//     {
//         for (size_t j = 0; j < SIZE - i - 1; j++)
//         {
//             int res = mySrtcmpFromLeft(str[j], str[j + 1]);
//             if (res > 0)
//             {
//                 char* buffer = str[j];
//                 str[j] = str[j + 1];
//                 str[j + 1] = buffer;
//             }
//         }
//     }
// }

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

void oneginSortedFile(char **str, size_t SIZE)
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

void printfSortedText(char **str, size_t SIZE)
{
    puts("Отсортированный текст:\n");
    for (size_t j = 0; j < SIZE; j++)
    {
        printf("%s\n", str[j]);
        free(str[j]);
    }
    free(str);
}







#if 0
void bubbleSort(char **str, size_t SIZE, int (sort*)(const char *, const char *))
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


int myStrcmpFromRight(char *pstr1, char *pstr2)
{
    size_t i = strlen(*pstr1) - 1, j = strlen(*pstr2) - 1;

    while (*pstr1[i] != '\0')
    {
        while (pstr1[i] != '\0' && isalnum((unsigned char)pstr1[i]))
            i--;
        while (pstr2[j] != '\0' && isalnum((unsigned char)pstr2[j]))
            j--;

        char ch1 = (char)tolower((unsigned char)pstr1[i]);
        char ch2 = (char)tolower((unsigned char)pstr2[j]);

        if (ch1 != ch2)
            break;

        i--;
        j--;
    }

    return pstr1[i] - pstr2[j];
}

#endif
