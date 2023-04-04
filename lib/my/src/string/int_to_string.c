/*
** EPITECH PROJECT, 2023
** pokedex.c
** File description:
** scene of pokedex
*/


#include <stdlib.h>

char *my_revstr(char *str);

char *change_itoa(int nb)
{
    char *str;
    int count;
    int save = nb;

    for (int i = 0; save != 0; i++) {
        save /= 10;
        count++;
    }
    str = malloc(sizeof(char) * (count + 1));
    for (int j = 0; nb != 0; j++) {
        str[j] = (nb % 10) + '0';
        nb /= 10;
    }
    str[count + 1] = '\0';
    str = my_revstr(str);
    return str;
}
