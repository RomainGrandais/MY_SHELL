/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** cp string in other string
*/

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
