/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** create tab with string
*/

#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <fcntl.h>

static int count_nb_lines(char const *str)
{
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            n++;
    return n;
}

static int count_lines(char const *str, int i)
{
    int n = 0;
    for (; str[i] != '\0' && str[i] != '\n'; i++)
        n++;
    return (n);
}

char **my_str_to_word_array(char const *str)
{
    int n = 0;
    int nb_lines = count_nb_lines(str);
    char **tab = malloc(sizeof(char *) * (nb_lines + 1));

    for (int i = 0; i < nb_lines; i++) {
        tab[i] = malloc(sizeof(char) * count_lines(str, n) + 1);
        tab[i][count_lines(str, n)] = '\0';
        while (str[n] != '\0' && str[n] == '\n')
            n++;
    }
    n = 0;
    for (int i = 0; i < nb_lines; i++) {
        for (int j = 0; str[n] != '\0' && str[n] != '\n'; j++) {
            tab[i][j] = str[n];
            n++;
        }
        for (;str[n] == '\n' && str[n] != '\0'; n++);
    }
    tab[nb_lines] = NULL;
    return tab;
}
