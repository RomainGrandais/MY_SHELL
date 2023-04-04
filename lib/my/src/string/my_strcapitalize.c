/*
** EPITECH PROJECT, 2022
** my_strcapitalize.C
** File description:
** capitalize first letter of words
*/

void my_putstr(char *str);

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[i] >= 'a' && str[i] <= 'z') {
        str[i + 1] = str[i + 1] - 32;
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' ')
            str[i] = str[i] - 32;
        i++;
    }
    my_putstr(str);
    return (str);
}
