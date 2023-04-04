/*
** EPITECH PROJECT, 2022
** Merge Stringss
** File description:
** Merge 2 strings and malloc
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);

char *concat_strings(char *src, char *dest)
{
    int size = (my_strlen(src) + my_strlen(dest));
    char *result = malloc(sizeof(char) * (size + 1));

    if (result == NULL)
        return (NULL);
    result = my_strcpy(result, src);
    my_strcat(result, dest);
    result[size] = '\0';
    return (result);
}
