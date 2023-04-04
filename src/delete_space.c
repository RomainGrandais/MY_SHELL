/*
** EPITECH PROJECT, 2023
** delete_space.c
** File description:
** delete space start of string
*/

#include "project.h"

char **remove_last_elem(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    if (my_strcmp(tab[i - 1], "") == 0)
        tab[i - 1] = NULL;
    return tab;
}

char *delete_space(char *str)
{
    int i = 0;
    char *str_no_space;

    for (; str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'); i++);
    str_no_space = my_strdup(&str[i]);
    if (str_no_space != NULL)
        return str_no_space;
    return str;
}
