#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

char* add_char(char c, char *str1) {
    strlen(str1);
    char *str2 = (char*)malloc((strlen(str1)+1) * sizeof(char));
    int i = 0;
    while(str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = c;
    ++i;
    str2[i] = '\0';
    free(str1);
    return str2;
}
