/*
** EPITECH PROJECT, 2023
** pipe_process.c
** File description:
** fonction for pipe process
*/

#include "project.h"

void fork_pipe_error(many_command_t *many)
{
    if (pipe(many->fd) == -1)
        exit(EXIT_FAILURE);
    if ((many->pid = fork()) == -1)
        exit(EXIT_FAILURE);
}

char **choice_exe(many_command_t *many, shell_t *shell, char **env, int i)
{
    if (is_my_command(many->all_command[i]) == 0)
        execve(many->all_command[i][0], many->all_command[i], NULL);
    else {
        shell->command = many->all_command[i];
        env = check_if_is_command(shell, env);
    }
    return env;
}

void change_process(many_command_t *many, int i)
{
    if (i + 1 != many->nb_cmd)
        dup2(many->fd[1], STDOUT_FILENO);
}

char **loop_pipe(many_command_t *many, shell_t *shell, char **env)
{
    int fd_in = 0;

    for (int i = 0; i < many->nb_cmd; i++) {
        fork_pipe_error(many);
        if (many->pid == 0) {
            dup2(fd_in, STDIN_FILENO);
            change_process(many, i);
            close(many->fd[0]);
            env = choice_exe(many, shell, env, i);
        } else {
            waitpid(many->pid, &many->status, 0);
            close(many->fd[1]);
            fd_in = many->fd[0];
        }
    }
    return env;
}
