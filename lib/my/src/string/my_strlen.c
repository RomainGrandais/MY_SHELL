/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** return the len of any string
*/

#include<stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}
