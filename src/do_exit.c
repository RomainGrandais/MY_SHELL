/*
** EPITECH PROJECT, 2023
** do_exit.c
** File description:
** do exit command
*/

#include "project.h"

int check_if_nb(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if (is_digit(arg[i]) == 0)
            return 1;
    }
    return 0;
}

int if_error(shell_t *shell)
{
    if (is_digit(shell->command[1][0]) == 0) {
            write(2, "exit: Expression Syntax.\n", 25);
            shell->error = 1;
            return 1;
        }
    if (check_if_nb(shell->command[1]) == 1) {
        write(2, "exit: Badly formed number.\n", 27);
        shell->error = 1;
        return 1;
    }
    return 0;
}

void if_one_arg(shell_t *shell, int nb_arg)
{
    int nb = 0;

    if (nb_arg == 1) {
        if (if_error(shell) == 1)
            return;
        nb = my_getnbr(shell->command[1]);
        if (nb < 0) {
            my_printf("exit\n");
            exit(256 + nb);
        }
        my_printf("exit\n");
        exit(nb);
    }
}

void do_exit(shell_t *shell)
{
    int nb_arg = count_args(shell->command);

    if (nb_arg == 0) {
        my_printf("exit\n");
        exit(shell->error);
    }
    if (nb_arg > 1) {
        shell->error = 1;
        if (is_digit(shell->command[1][0]) == 0) {
            write(2, "exit: Expression Syntax.\n", 25);
            return;
        }
        write(2, "exit: Badly formed number.\n", 27);
    }
    if_one_arg(shell, nb_arg);
}
