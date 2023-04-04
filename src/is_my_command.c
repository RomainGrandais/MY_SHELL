/*
** EPITECH PROJECT, 2023
** is_my_command.c
** File description:
** chack if command in shell is my
*/

#include "project.h"

char **check_if_is_command(shell_t *shell, char **env)
{
    if (my_strcmp(shell->command[0], "exit") == 0)
        do_exit(shell);
    if (my_strcmp(shell->command[0], "cd") == 0)
        env = do_cd(shell, env);
    if (my_strcmp(shell->command[0], "env") == 0)
        do_env(shell, env);
    if (my_strcmp(shell->command[0], "setenv") == 0)
        env = do_setenv(shell, env);
    if (my_strcmp(shell->command[0], "unsetenv") == 0)
        env = do_unsetenv(shell, env);
    if (my_strcmp(shell->command[0], "echo") == 0 &&
        my_strcmp(shell->command[1], "$?") == 0)
        my_printf("%d\n", shell->error);
    return env;
}

int is_my_command(char **command)
{
    if (my_strcmp(command[0], "cd") == 0 ||
        my_strcmp(command[0], "setenv") == 0 ||
        my_strcmp(command[0], "env") == 0 ||
        my_strcmp(command[0], "unsetenv") == 0 ||
        my_strcmp(command[0], "exit") == 0 ||
        (my_strcmp(command[0], "echo") == 0 &&
        my_strcmp(command[1], "$?") == 0)) {
            return 1;
        }
    return 0;
}
