/*
** EPITECH PROJECT, 2023
** do_env.c
** File description:
** do env command
*/

#include "project.h"

void do_env(shell_t *shell, char **env)
{
    if (count_args(shell->command) == 0)
        my_show_word_array(env);
    if (count_args(shell->command) > 0)
        write(2, "Too many arguments : env takes no arguments\n", 45);
}
