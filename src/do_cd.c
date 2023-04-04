/*
** EPITECH PROJECT, 2023
** do_cd.c
** File description:
** do command cd in y shell
*/

#include "project.h"

int cd_error_gestion(shell_t *shell)
{
    struct stat buff;

    if (stat(shell->command[1], &buff) == 0) {
        if (S_ISDIR(buff.st_mode) == 0) {
        write(2, shell->command[1], my_strlen(shell->command[1]));
        write(2, ": Not a directory.\n", 19);
        return 1;
        }
    }
    if (access(shell->command[1], F_OK) != 0) {
        write(2, shell->command[1], my_strlen(shell->command[1]));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    if (access(shell->command[1], R_OK) != 0) {
        write(2, shell->command[1], my_strlen(shell->command[1]));
        write(2, ": Permission denied.\n", 21);
        return 1;
    }
    return 0;
}

void change_dir(shell_t *shell, char *path)
{
    char save[256];

    getcwd(save, 256);
    chdir(path);
    shell->path_before = my_strdup(save);
    getcwd(save, 256);
    shell->path_now = my_strdup(save);
}

int many_arg(shell_t *shell)
{
    if (count_args(shell->command) > 1) {
        write(2, "cd: Too many arguments.\n", 24);
        shell->error = 1;
        return 1;
    }
    return 0;
}

int do_back(shell_t *shell)
{
    if (my_strcmp("-", shell->command[1]) == 0) {
        if (shell->path_before == NULL) {
            write(2, ": No such file or directory.\n", 29);
            shell->error = 1;
            return 1;
        }
        change_dir(shell, shell->path_before);
        return 0;
    }
    return 1;
}

char **do_cd(shell_t *shell, char **env)
{
    if (many_arg(shell) == 1)
        return env;
    if (count_args(shell->command) == 0 ||
        my_strcmp("~", shell->command[1]) == 0 ||
        my_strcmp("--", shell->command[1]) == 0) {
        change_dir(shell, shell->home_path);
        }
    if (count_args(shell->command) == 1 &&
        my_strcmp("~", shell->command[1]) != 0 &&
        my_strcmp("-", shell->command[1]) != 0) {
            if (cd_error_gestion(shell) == 1) {
                shell->error = 1;
                return env;
            }
            change_dir(shell, shell->command[1]);
    }
    if (do_back(shell) == 1)
            return env;
    env = change_pwd(shell, env);
    return env;
}
