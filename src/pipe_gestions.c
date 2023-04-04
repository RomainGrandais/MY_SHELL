/*
** EPITECH PROJECT, 2023
** pipe_gestions.c
** File description:
** gestion pipe in command
*/

#include "project.h"

int count_nb_elem(char **command)
{
    int count = 0;

    for (int i = 0; command[i] != NULL; i++)
        count++;
    return count;
}

char **execute_pipe(many_command_t *many, shell_t *shell, char **env)
{
    env = loop_pipe(many, shell, env);
    return env;
}

char **setup_pipe(shell_t *shell, char *command, char **env)
{
    char **tab = my_strtok(command, '|');

    shell->many->nb_cmd = count_nb_elem(tab);
    shell->many->all_command = malloc(sizeof(char **) *
        (shell->many->nb_cmd + 1));
    shell->many->all_command[shell->many->nb_cmd] = NULL;
    for (int i = 0; i < shell->many->nb_cmd; i++) {
        tab[i] = delete_space(tab[i]);
        shell->many->all_command[i] = str_to_array_space(tab[i]);
        shell->many->all_command[i] =
            remove_last_elem(shell->many->all_command[i]);
        shell->command = shell->many->all_command[i];
        shell->many->all_command[i][0] = find_path(shell, env);
    }
    env = execute_pipe(shell->many, shell, env);
    return env;
}
