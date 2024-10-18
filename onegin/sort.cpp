#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void readFile(char ***str, size_t *SIZE, size_t *row_count);
void resultOfReadFile(char **str, size_t SIZE);
int my_strcmp(const char *pstr1, const char *pstr2);
void bubbleSort(char **str, size_t size);
void oneginSortedFile(char **str, size_t SIZE);
void printfSortedText(char **str, size_t SIZE);



int main()
{
    size_t SIZE = 0;
    size_t row_count = 10;

    char **str = (char**)calloc(row_count, sizeof(char*));
    assert(str != NULL);

    readFile(&str, &SIZE, &row_count);

    resultOfReadFile(str, SIZE);

    bubbleSort(str, SIZE);

    oneginSortedFile(str, SIZE);

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

int my_strcmp(const char *pstr1, const char *pstr2)
{
    int i = 0, j = 0;
    while(1)
    {
        while(pstr1[i] != '\0' && !isalnum((unsigned char)pstr1[i]))
            i++;
        while(pstr2[j] != '\0' && !isalnum((unsigned char)pstr2[j]))
            j++;

        char ch1 = (pstr1[i] != '\0') ? (char)tolower((unsigned char)pstr1[i]) : '\0';
        char ch2 = (pstr2[j] != '\0') ? (char)tolower((unsigned char)pstr2[j]) : '\0';

        if (ch1 == ch2)
        {
            if(ch1 == '\0')
                return 0;
            i++;
            j++;
        }
        else
            return ch1 - ch2;
    }
}

void bubbleSort(char **str, size_t SIZE)
{
    for (size_t i = 0; i < SIZE - 1; i++)
    {
        for (size_t j = 0; j < SIZE - i - 1; j++)
        {
            int res = my_strcmp(str[j], str[j + 1]);
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
    FILE *fp = fopen("onegin_sorted.txt", "w");
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
