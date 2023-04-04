/*
** EPITECH PROJECT, 2022
** body_bsq.c
** File description:
** make buffer
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>

char *make_buffer_ws(char const *file)
{
    struct stat statbuf;
    char *buffer;
    unsigned int size;
    int fd = open(file, O_RDONLY);
    int error;

    if (fd < 0)
        return NULL;
    stat(file, &statbuf);
    size = statbuf.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    error = read(fd, buffer, size);
    buffer[size] = '\0';
    if (error < 0)
        return NULL;
    close(fd);
    return (buffer);
}
