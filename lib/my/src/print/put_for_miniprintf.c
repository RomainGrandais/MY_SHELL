/*
** EPITECH PROJECT, 2022
** put_for_mini_printf.c
** File description:
** putchar putstr and putnbr
*/

#include <unistd.h>

void my_putchar_printf(char c, int *len)
{
    write(1, &c, 1);
    (*len)++;
}

void my_putstr_printf(char const *str, int *len)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_printf(str[i], len);
        i += 1;
    }
}

void my_put_nbr_printf(int nb, int *len)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar_printf('-', len);
    }
    if (nb > 9) {
        my_put_nbr_printf(nb / 10, len);
        my_put_nbr_printf(nb % 10, len);
    }
    if (nb <= 9) {
        my_putchar_printf(nb + '0', len);
    }
}
