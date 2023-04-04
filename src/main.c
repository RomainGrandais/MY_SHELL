/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main for minishell_1
*/

#include "project.h"

int count_args(char **params_exe)
{
    int count = 0;

    for (int i = 1; params_exe[i] != NULL; i++)
        count++;
    return count;
}

void my_shell(shell_t shell, char **env)
{
    while (1) {
        get_command(&shell);
        if (my_strcmp(shell.answer, "") == 0)
            continue;
        if (shell.sepa->split == 1) {
            many_command(&shell, env);
            continue;
        }
        if (is_pipe(shell.answer) == 0) {
            setup_pipe(&shell, shell.answer, env);
            continue;
        }
        shell.command = str_to_array_space(shell.answer);
        shell.command = remove_last_elem(shell.command);
        if (is_my_command(shell.command) == 1) {
            env = check_if_is_command(&shell, env);
            continue;
        }
        execute_command(&shell, env);
    }
}

int main(int ac, char **av, char **env)
{
    shell_t shell = {0};
    int count = 0;

    if (ac != 1)
        return 84;
    shell.answer = malloc(sizeof(char) * 80);
    for (; env[count] != NULL; count++);
    shell.size_env_begin = count;
    shell.size_env_now = shell.size_env_begin;
    shell.home_path = get_env("HOME", env);
    shell.path_command = get_env("PATH", env);
    shell.pid = getpid();
    shell.error = 0;
    shell.sepa = malloc(sizeof(separator_t));
    shell.many = malloc(sizeof(many_command_t));
    my_shell(shell, env);
    free_all(&shell, env);
    return shell.error;
}
