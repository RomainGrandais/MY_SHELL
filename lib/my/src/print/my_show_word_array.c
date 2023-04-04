/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** show tab of word in terminal
*/

#include <stddef.h>

void my_putchar(char c);
void my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
