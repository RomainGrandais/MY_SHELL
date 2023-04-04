/*
** EPITECH PROJECT, 2022
** make_buffer.c
** File description:
** make buffer
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>

char *make_buffer(char const *file, int size)
{
    char *buffer;
    int fd = open(file, O_RDONLY);
    int error;

    if (fd < 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    error = read(fd, buffer, size);
    buffer[size] = '\0';
    if (error < 0)
        return NULL;
    close(fd);
    return (buffer);
}
