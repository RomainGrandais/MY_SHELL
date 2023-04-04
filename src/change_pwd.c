/*
** EPITECH PROJECT, 2023
** change_pwd.c
** File description:
** change pwd in env
*/

#include "project.h"

char **change_pwd(shell_t *shell, char **env)
{
    char **tab = malloc(sizeof(char *) * 4);

    tab[0] = my_strdup("setennv");
    tab[1] = my_strdup("PWD");
    tab[2] = my_strdup(shell->path_now);
    tab[3] = NULL;
    shell->command = tab;
    env = do_setenv(shell, env);
    tab[1] = my_strdup("OLDPWD");
    tab[2] = my_strdup(shell->path_before);
    shell->command = tab;
    env = do_setenv(shell, env);
    return env;
}
