/*
** EPITECH PROJECT, 2023
** find_in_env.c
** File description:
** find if name is in env
*/

#include "project.h"

int find_in_env(char *name, char **env)
{
    int name_size = my_strlen(name);

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, name_size) == 0 &&
            env[i][name_size] == '=') {
            return i;
        }
    }
    return -1;
}
