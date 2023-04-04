/*
** EPITECH PROJECT, 2022
** is_digit.c
** File description:
** if argument is a digit
*/

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
