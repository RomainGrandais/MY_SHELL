/*
** EPITECH PROJECT, 2023
** free_all.c
** File description:
** free al vriable
*/

#include "project.h"

void free_all(shell_t *shell, char **env)
{
    if (shell->answer != NULL)
        free(shell->answer);
    if (shell->home_path != NULL)
        free(shell->home_path);
    if (shell->path_command != NULL)
        free(shell->path_command);
    if (shell->path_now != NULL)
        free(shell->path_now);
    for (int i = 0; shell->command[i] != NULL; i++)
        free(shell->command[i]);
    if (shell->command != NULL)
        free(shell->command);
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    if (env != NULL)
        free(env);
}
