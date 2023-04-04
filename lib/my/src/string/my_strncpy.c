/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** cp n characters of one string
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);

    for (int i = 0; i < len; i++) {
        if (i < n)
            dest[i] = src[i];
        else {
            dest[i] = '\0';
            return (dest);
        }
    }
    return (dest);
}
