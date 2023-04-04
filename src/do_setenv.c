/*
** EPITECH PROJECT, 2023
** do_setenv.c
** File description:
** set variable in env
*/

#include "project.h"

int is_alpha(char c)
{
    if (is_letters(c) == 0 && is_digit(c) == 0)
        return 0;
    return 1;
}

int check_command(char **command, shell_t *shell, char **env)
{
    if (count_args(command) == 0) {
        do_env(shell, env);
        return 2;
    }
    if (is_letters(command[1][0]) == 0 && command[1][0] != '_') {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 0;
    }
    for (int i = 0; command[1][i] != '\0'; i++) {
        if (is_alpha(command[1][i]) == 0 && command[1][i] != '_') {
            write(2, "setenv: Variable name ", 22);
            write(2, "must contain alphanumeric characters.\n", 38);
            return 0;
        }
    }
    if (count_args(command) > 2) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 0;
    }
    return 1;
}

char **copy_env(shell_t *shell, char **env, int size)
{
    char **tab = malloc(sizeof(char *) * (shell->size_env_now + size + 1));

    for (int i = 0; i < shell->size_env_now; i++)
        tab[i] = env[i];
    return tab;
}

char **if_not_in_env(shell_t *shell, char **env, char **tab, char *line_add)
{
    if (find_in_env(shell->command[1], env) == -1) {
        tab = copy_env(shell, env, 1);
        tab[shell->size_env_now] = line_add;
        tab[shell->size_env_now + 1] = NULL;
        shell->size_env_now++;
    }
    return tab;
}

char **do_setenv(shell_t *shell, char **env)
{
    char **tab = copy_env(shell, env, 0);
    char *line_add;
    int index;
    int error = 0;

    if ((error = check_command(shell->command, shell, env)) == 1) {
        line_add = concat_strings(shell->command[1], "=");
        if (count_args(shell->command) == 2)
            line_add = concat_strings(line_add, shell->command[2]);
        tab = if_not_in_env(shell, env, tab, line_add);
        if ((index = find_in_env(shell->command[1], env)) != -1) {
            tab[index] = line_add;
        }
    }
    if (error == 0)
        shell->error = 1;
    return tab;
}
