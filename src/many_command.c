/*
** EPITECH PROJECT, 2023
** many_command.c
** File description:
** if in command shell have ;
*/

#include "project.h"

int is_pipe(char *command)
{
    int size = my_strlen(command);

    for (int i = 0; i < size; i++) {
        if (command[i] == '|')
            return 0;
    }
    return 1;
}

char **many_command(shell_t *shell, char **env)
{
    char **sepa_command = my_strtok(shell->answer, ';');

    sepa_command = remove_last_elem(sepa_command);
    for (int i = 0; sepa_command[i] != NULL; i++)
        sepa_command[i] = delete_space(sepa_command[i]);
    for (int i = 0; sepa_command[i] != NULL; i++) {
        shell->command = str_to_array_space(sepa_command[i]);
        shell->command = remove_last_elem(shell->command);
        if (is_pipe(sepa_command[i]) == 0) {
            env = setup_pipe(shell, sepa_command[i], env);
            continue;
        }
        if (is_my_command(shell->command) == 1)
            env = check_if_is_command(shell, env);
        else
            execute_command(shell, env);
    }
    return env;
}
