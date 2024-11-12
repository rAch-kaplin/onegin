#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "comparator.h"


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

int myStrcmpFromRight(const char *pstr1, const char *pstr2) //TODO: struct element
{
    size_t i = strlen(pstr1) - 1, j = strlen(pstr2) - 1;

    while (1)
    {
        while (!isalnum((unsigned char)pstr1[i]))
        {
            i--;
        }

        while (!isalnum((unsigned char)pstr2[j]))
        {
            j--;
        }

        if (i == 0 || j == 0)
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


