/*
** EPITECH PROJECT, 2023
** is_letters.c
** File description:
** is char is a lettter
*/

int is_letters(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}
