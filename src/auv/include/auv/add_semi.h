#include <string.h>
#include <stdlib.h>
char* add_semi(char s[])
{
    int i;
    char *p = NULL;
    p = (char*)malloc(sizeof(char)*(strlen(s)+4));
    strcpy(p, s);
    *(p+strlen(s)) = ',';
    *(p+strlen(s)+1) = '\n';
    *(p+strlen(s)+2) = '\r';
    return p;
    free(p);
}