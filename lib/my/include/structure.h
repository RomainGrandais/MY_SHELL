/*
** EPITECH PROJECT, 2022
** structure.h
** File description:
** structure for bsq
*/

#ifndef __STRUCTURE_H_
    #define __STRUCTURE_H_

typedef struct separator_s{
    int split;
    int pipe;
    int redirection;
}separator_t;

typedef struct many_command_s{
    char ***all_command;
    int nb_cmd;
    int status;
    pid_t pid;
    int fd[2];
}many_command_t;

typedef struct shell {
    char *answer;
    char **command;
    char *home_path;
    char *path_command;
    char *path_now;
    char *path_before;
    int size_env_begin;
    int size_env_now;
    int error;
    pid_t pid;
    separator_t *sepa;
    many_command_t *many;
}shell_t;

#endif
