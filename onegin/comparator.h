#ifndef _HCOMPARATOR
#define _HCOMPARATOR

#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_RESET   "\x1b[0m"

typedef struct
{
    const char *str;
    size_t len;
} StringElement;

int mySrtcmpFromLeft(const StringElement *pstr1, const StringElement *pstr2);
int myStrcmpFromRight(const StringElement *pstr1, const StringElement *pstr2);

#endif
