/*
** EPITECH PROJECT, 2023
** get_path_command.c
** File description:
** get the path of system command
*/

#include "project.h"

char *get_env(const char *name, char **env)
{
    int name_size = my_strlen(name);

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, name_size) == 0 &&
            env[i][name_size] == '=') {
            return &env[i][name_size + 1];
        }
    }
    return NULL;
}
