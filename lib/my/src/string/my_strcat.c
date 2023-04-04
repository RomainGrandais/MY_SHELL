/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** concatenates two string
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, const char *src, int n);

char *my_strcat(char *dest, char const *src)
{
    int len_src = my_strlen(src);

    return (my_strncat(dest, src, len_src));
}
