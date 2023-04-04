/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** find a number in string and if is a positive or negative
*/

int my_getnbr(char const *str)
{
    int	nb = 0;
    int	isneg = 1;
    int	i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            isneg = isneg * -1;
            i = i + 1;
        }
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        } else
            return (nb * isneg);
    }
    return (nb * isneg);
}
