/*
** EPITECH PROJECT, 2023
** do_unsetenv.c
** File description:
** do unsetenv command
*/

#include "project.h"

char **remove_line(shell_t *shell, char **env, int index)
{
    char **tab = malloc(sizeof(char *) * (shell->size_env_now));
    int j = 0;

    for (int i = 0; i < shell->size_env_now; i++) {
        if (i != index) {
            tab[j] = env[i];
            j++;
        }
    }
    tab[shell->size_env_now - 1] = NULL;
    return tab;
}

char **do_unsetenv(shell_t *shell, char **env)
{
    int index = 0;

    if (count_args(shell->command) == 0) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        shell->error = 1;
        return env;
    }
    for (int i = 1; shell->command[i] != NULL; i++) {
        if ((index = find_in_env(shell->command[i], env)) != -1) {
            env = remove_line(shell, env, index);
            shell->size_env_now--;
        }
    }
    shell->error = 0;
    return env;
}
