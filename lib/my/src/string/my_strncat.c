/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** concatenante n characters of src in dest
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, const char *src, int n)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0 ; i < n && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return (dest);
}
