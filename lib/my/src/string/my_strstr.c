/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** find the first occurence of second string in the first string
*/

#include <stdlib.h>

int my_strncmp(const char *s1, const char *s2, int n);
int my_strlen(char const *str);

char *my_strstr(const char *line, const char *motif)
{
    int line_len = my_strlen(line);
    int motif_len = my_strlen(motif);

    for (int i = 0; i <= line_len - motif_len; i++) {
        if (my_strncmp(line + i, motif, motif_len) == 0)
            return (char *)line + i;
    }
    return NULL;
}
