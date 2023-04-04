/*
** EPITECH PROJECT, 2023
** find_path.c
** File description:
** find path of sys command
*/

#include "project.h"

char *get_env(const char *name, char **env);

char *cut_find_dir(shell_t *shell, char *path_token,
    int len_command, char *path_cpy)
{
    int len_dir;
    char *file_path;
    struct stat buff;

    while (path_token != NULL) {
        len_dir = my_strlen(path_token);
        file_path = malloc(sizeof(char) *
            len_command + len_dir + 2);
        file_path = concat_strings(concat_strings(path_token, "/"),
            concat_strings(shell->command[0], "\0"));
        if (stat(file_path, &buff) == 0) {
            free(path_cpy);
            return file_path;
        } else {
            free(file_path);
            path_token = strtok(NULL, ":");
        }
    }
    return NULL;
}

char *find_path(shell_t *shell, char **env)
{
    char *path_cpy;
    char *path_token;
    int len_command;
    struct stat buff;
    char *file_path;

    shell->path_command = get_env("PATH", env);
    if (shell->path_command) {
        path_cpy = my_strdup(shell->path_command);
        len_command = my_strlen(shell->command[0]);
        path_token = strtok(path_cpy, ":");
        if ((file_path = cut_find_dir(shell, path_token,
            len_command, path_cpy)) != NULL)
            return file_path;
        free(path_cpy);
        if (stat(shell->command[0], &buff) == 0)
            return shell->command[0];
        return shell->command[0];
    }
    return shell->command[0];
}
