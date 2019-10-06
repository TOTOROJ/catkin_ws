#include <string.h>
#include <stdlib.h>
char* add_comma(char s[])
{
    int i;
    char *p = NULL;
    p = (char*)malloc(sizeof(char)*(strlen(s)+2));
    strcpy(p, s);
    *(p+strlen(s)) = ',';
    return p;
    free(p);
}
