/*
** EPITECH PROJECT, 2022
** lib in h
** File description:
** lib
*/

#ifndef PROJECT_H_
    #define PROJECT_H_

    #define _GNU_SOURCE
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <unistd.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "my.h"
    #include "structure.h"

char **many_command(shell_t *shell, char **env);
char *delete_space(char *str);
int cd_error_gestion(shell_t *shell);
char **change_pwd(shell_t *shell, char **env);
char **do_cd(shell_t *shell, char **env);
void do_env(shell_t *shell, char **env);
int check_if_nb(char *arg);
void if_one_arg(shell_t *shell, int nb_arg);
void do_exit(shell_t *shell);
int check_command(char **command, shell_t *shell, char **env);
char **copy_env(shell_t *shell, char **env, int size);
char **do_setenv(shell_t *shell, char **env);
char **remove_line(shell_t *shell, char **env, int index);
char **do_unsetenv(shell_t *shell, char **env);
char **check_if_is_command(shell_t *shell, char **env);
void get_command(shell_t *shell);
void manage_sig(int wait, shell_t *shell);
void do_exe(shell_t *shell, char **env, char *command);
void execute_command(shell_t *shell, char **env);
int find_in_env(char *name, char **env);
char *find_path(shell_t *shell, char **env);
char *cut_find_dir(shell_t *shell, char *path_token,
    int len_command, char *path_cpy);
void free_all(shell_t *shell, char **env);
char *get_env(const char *name, char **env);
int count_args(char **params_exe);
void my_shell(shell_t shell, char **env);
int main(int ac, char **av, char **env);
char **remove_last_elem(char **tab);
void cd_back(shell_t *shell, char **env);
int is_my_command(char **command);
int is_pipe(char *command);
char **setup_pipe(shell_t *shell, char *command, char **env);
char **loop_pipe(many_command_t *many, shell_t *shell, char **env);

#endif
