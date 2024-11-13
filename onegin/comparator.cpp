#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "comparator.h"
#include <assert.h>



int mySrtcmpFromLeft(const StringElement *pstr1, const StringElement *pstr2)
{
    int i = 0, j = 0;

    while (pstr1->str[i] != '\0')
    {
        while (pstr1->str[i] != '\0' && !isalnum((unsigned char)pstr1->str[i]))
            i++;
        while (pstr2->str[j] != '\0' && !isalnum((unsigned char)pstr2->str[j]))
            j++;

        char ch1 = (char)tolower((unsigned char)pstr1->str[i]);
        char ch2 = (char)tolower((unsigned char)pstr2->str[j]);

        if (ch1 != ch2)
            break;

        i++;
        j++;
    }

    return pstr1->str[i] - pstr2->str[j];
}

int myStrcmpFromRight(const StringElement *pstr1, const StringElement *pstr2) //TODO: struct element
{
    size_t i = pstr1->len, j = pstr2->len;

    while (1)
    {
        while (!isalnum((unsigned char)pstr1->str[i]))
        {
            fprintf(stderr, COLOR_YELLOW "i = %zu\n" COLOR_RESET, i);
            i--;
        }

        while (!isalnum((unsigned char)pstr2->str[j]))
        {
            j--;
            fprintf(stderr, COLOR_YELLOW "j = %zu\n" COLOR_RESET, j);
        }

        if (i == 0 || j == 0)
            break;

        char ch1 = (char)tolower((unsigned char)pstr1->str[i]);
        char ch2 = (char)tolower((unsigned char)pstr2->str[j]);

        if (ch1 != ch2)
            break;

        i--;
        j--;
    }

    return pstr1->str[i] - pstr2->str[j];
}
