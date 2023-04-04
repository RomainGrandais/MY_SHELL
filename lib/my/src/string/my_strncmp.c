/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** compare two string
*/

int my_strncmp(const char *str1, const char *str2, int n)
{
    while (n > 0) {
        if (*str1 != *str2)
            return (*str1 < *str2) ? -1 : 1;
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
        n--;
    }
    return 0;
}
