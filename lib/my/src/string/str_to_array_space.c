/*
** EPITECH PROJECT, 2022
** My str to word array
** File description:
** STR to word array
*/

#include <stddef.h>
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2);

int count_words(char const *str)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i + 1] == '\0' || str[i] == '\t') &&
            str[i + 1] != ' ' && str[i + 1] != '\t') {
            c++;
        }
    }
    return (c);
}

int len_word(char const *str, int i)
{
    int c = 0;

    for (; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; i++)
        c++;
    return (c);
}

static void add_to_array(char *dest, char const *str, int *j, int i)
{
    dest[*j] = str[i];
    *j = *j + 1;
}

char **str_to_array_space(char const *str)
{
    char **tab = malloc(sizeof(char *) * (count_words(str) + 1));
    char *dest = malloc(sizeof(char) * (len_word(str, 0)));
    int j = 0;
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') &&
            (str[i + 1] != ' ' && str[i + 1] != '\n' &&
            str[i + 1] != '\t')) {
            tab[n] = dest;
            dest = malloc(sizeof(char) * (len_word(str, i + 1)));
            j = 0;
            n++;
        }
        if (str[i] != ' ' && str[i] != '\t')
            add_to_array(dest, str, &j, i);
    }
    tab[n] = dest;
    tab[n + 1] = NULL;
    return (tab);
}
