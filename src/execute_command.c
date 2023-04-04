/*
** EPITECH PROJECT, 2023
** execute_command.c
** File description:
** exe command in my shell
*/

#include "project.h"

void manage_sig(int wait, shell_t *shell)
{
    int signal = 0;

    shell->error = wait;
    signal = WTERMSIG(wait);
    if (signal == 8) {
        write(2, "Floating exception", 18);
    } else
        write(2, strsignal(signal), my_strlen(strsignal(signal)));
    if (WCOREDUMP(wait))
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
}

void do_exe(shell_t *shell, char **env, char *command)
{
    struct stat buff;

    if (execve(command, shell->command, env) == -1) {
        shell->error = 1;
        write(2, shell->command[0], my_strlen(shell->command[0]));
        if (errno == 8) {
            write(2, ": Exec format error. Wrong Architecture.\n", 41);
            exit(1);
        }
        if (errno == EACCES) {
            write(2, ": Permission denied.\n", 21);
            exit(1);
        }
        if (stat(shell->command[0], &buff) == -1) {
            write(2, ": Command not found.\n", 21);
            exit(1);
        }
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
}

void execute_command(shell_t *shell, char **env)
{
    int wait = 0;
    char *command;

    command = find_path(shell, env);
    shell->pid = fork();
    if (access(command, 0) == -1 && shell->pid == 0) {
        do_exe(shell, env, command);
        return;
    }
    if (shell->pid == -1)
        return;
    if (shell->pid == 0) {
        do_exe(shell, env, command);
    } else {
        waitpid(shell->pid, &wait, 0);
        shell->error = WEXITSTATUS(wait);
    }
    if (WIFSIGNALED(wait))
        manage_sig(wait, shell);
}
