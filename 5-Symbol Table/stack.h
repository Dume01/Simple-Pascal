#include <stdio.h>

#define MAX_STRINGS 5
#define MAX_LENGTH 100

int l=0;
// Global array of strings
char strings[MAX_STRINGS][MAX_LENGTH];

void insert(char* cx)
{
    strcpy(strings[l], cx);
    l++;
}

char* pop()
{   
    l--;
    char* anss=strdup(strings[l]);
    return anss;
}
