/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse a string
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    char f;
    int n = my_strlen(str) - 1;

    for (int i = 0; i < n; i++) {
        f = str[i];
        str[i] = str[n];
        str[n] = f;
        n--;
    }
    return (str);
}
