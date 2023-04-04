/*
** EPITECH PROJECT, 2023
** my_strtok.c
** File description:
** make array with a separator
*/

#include <stddef.h>
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2);

static int count_words(char const *str, char c)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == c || str[i + 1] == '\0') &&
            str[i + 1] != c) {
            j++;
        }
    }
    return (j);
}

static int len_word(char const *str, int i, char c)
{
    int j = 0;

    for (; str[i] != c && str[i] != '\0'; i++)
        j++;
    return (j);
}

static void add_to_array(char *dest, char const *str, int *j, int i)
{
    dest[*j] = str[i];
    *j = *j + 1;
}

char **my_strtok(char const *str, char c)
{
    char **tab = malloc(sizeof(char *) * (count_words(str, c) + 1));
    char *dest = malloc(sizeof(char) * (len_word(str, 0, c)));
    int j = 0;
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && str[i + 1] != c) {
            tab[n] = dest;
            dest = malloc(sizeof(char) * (len_word(str, i + 1, c)));
            j = 0;
            n++;
        }
        if (str[i] != c)
            add_to_array(dest, str, &j, i);
    }
    tab[n] = dest;
    tab[n + 1] = NULL;
    return (tab);
}
