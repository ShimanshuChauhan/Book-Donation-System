#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *trim(char *str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    // Find the first non-whitespace character
    while (isspace(str[start]))
    {
        start++;
    }

    // Find the last non-whitespace character
    while (end >= 0 && isspace(str[end]))
    {
        end--;
    }

    // Copy trimmed string to a new buffer
    int trimmed_len = end - start + 1;
    char *trimmed = (char *)malloc((trimmed_len + 1) * sizeof(char));
    strncpy(trimmed, &str[start], trimmed_len);
    trimmed[trimmed_len] = '\0';

    return trimmed;
}
