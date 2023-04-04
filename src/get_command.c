/*
** EPITECH PROJECT, 2023
** get_command.c
** File description:
** get command in shell
*/

#include "project.h"

void if_pipe(shell_t *shell)
{
    int size = my_strlen(shell->answer);

    for (int i = 0; i < size; i++) {
        if (shell->answer[i] == ';')
            shell->sepa->split = 1;
    }
}

void get_command(shell_t *shell)
{
    int check = 0;
    size_t size = 256;

    if (isatty(0) == 1)
        my_printf("$> ");
    check = getline(&shell->answer, &size, stdin);
    if (check == -1) {
        if (isatty(0) == 1)
            my_printf("exit\n");
        exit(shell->error);
    }
    size = my_strlen(shell->answer);
    if (size > 0 && shell->answer[size - 1] == '\n')
        shell->answer[size - 1] = '\0';
    shell->answer = delete_space(shell->answer);
    if_pipe(shell);
}
