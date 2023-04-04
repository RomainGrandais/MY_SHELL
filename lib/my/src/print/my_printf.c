/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** make mini printf
*/

#include <unistd.h>
#include <stdarg.h>

int my_putchar_printf(char c, int *len);
int my_putstr_printf(char const *str, int *len);
int my_put_nbr_printf(int nb, int *len);

static int error_gest(const char *s)
{
    char c;
    int i = 0;
    int error = 0;

    while (s[i] != '\0') {
        c = s[i + 1];
        if (s[i] == '%' && c == 'd')
            return (error);
        if (s[i] == '%' && c == 'i')
            return (error);
        if (s[i] == '%' && c == 's')
            return (error);
        if (s[i] == '%' && c == 'c')
            return (error);
        if (s[i] == '%' && c == '%')
            return (error);
        i++;
    }
    return (error - 1);
}

static void choose_flag_str(const char *s, va_list list, int i, int *len)
{
    if (s[i] == 's' && s[i - 1] == '%')
        my_putstr_printf(va_arg(list, char *), len);
    if (s[i] == 'c' && s[i - 1] == '%')
        my_putchar_printf(va_arg(list, int), len);
    if (s[i] == '%' && s[i + 1] == '%')
        my_putchar_printf('%', len);
}

static void choose_flag_int(const char *s, va_list list, int i, int *len)
{
    if (s[i] == 'd' && s[i - 1] == '%')
        my_put_nbr_printf(va_arg(list, int), len);
    if (s[i] == 'i' && s[i - 1] == '%')
        my_put_nbr_printf(va_arg(list, int), len);
    choose_flag_str(s, list, i, len);
}

int my_printf(const char *s, ...)
{
    int len = 0;
    int i = 0;
    va_list list;
    int result;
    int err = error_gest(s);

    va_start(list, s);
    while (s[i] != '\0') {
        result = len;
        choose_flag_int(s, list, i, &len);
        if (result == len && s[i] != '%')
            my_putchar_printf(s[i], &len);
        i++;
    }
    if (err == -1)
        return (err);
    va_end(list);
    return (len);
}
