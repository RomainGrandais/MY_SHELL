/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** puts every letter in lowcase
*/

void my_putstr(char *str);

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    my_putstr(str);
    return (str);
}
