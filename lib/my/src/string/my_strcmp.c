/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare 2 char *
*/

int my_strlen(char const *str);

int compare_string(char const *str_1, char const *str_2)
{
    for (int i = 0; str_1[i] != '\0' && str_2[i] != '\0'; i++) {
        if (str_1[i] != str_2[i])
            return 0;
    }
    return 1;
}

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int i;

    if (len_s1 > len_s2) {
        i = len_s2;
        return (s1[i] * 1);
    }
    if (len_s1 < len_s2) {
        i = len_s1;
        return (s2[i] * -1);
    }
    if (len_s1 == len_s2) {
        if (compare_string(s1, s2) == 1)
            return (0);
    }
    return (1);
}
