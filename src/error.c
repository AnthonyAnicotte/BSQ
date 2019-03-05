/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** Created by Anthony Anicotte,
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"
#include "function.h"

int check_charac(char *buffer)
{
    int j = 0;
    int i = 0;

    while (buffer[j] != '\n') {
        if (buffer[j] == '\0')
            return (1);
        j++;
    }
    i = j + 1;
    while (buffer[i] != '\0') {
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n' &&
            buffer[i] != '\0')
            return (1);
        i++;
    }
    return (0);
}

int check_line_len(char *buffer)
{
    error_struct_t *error_struct = malloc(sizeof(error_struct_t));

    init_error_struct(error_struct);
    init_variables(error_struct, buffer);
    if (error_struct->total_char == 1) {
        free(error_struct);
        return (1);
    }
    if (my_getnbr(buffer) * error_struct->first_line_len !=
        error_struct->total_char ||
        error_struct->first_line_len * error_struct->sure_line !=
            error_struct->total_char ||
        error_struct->sure_line != my_getnbr(buffer) ||
        error_struct->sure_line < 1) {
        free(error_struct);
        return (1);
    }
    free(error_struct);
    return (0);
}

int check_all(char *buffer, ssize_t nb)
{
    if (nb == 0)
        return (1);
    if (my_getnbr(buffer) == -1 || buffer[0] == '-' || my_getnbr(buffer) < 1)
        return (1);
    if (check_charac(buffer) == 1)
        return (1);
    if (check_line_len(buffer) == 1)
        return (1);
    return (0);
}

int read_map_error(int fd, char **av)
{
    struct stat buf;
    char *buffer;
    ssize_t nb;

    stat(av[1], &buf);
    buffer = malloc(sizeof(char) * buf.st_size + 1);
    nb = read(fd, buffer, (size_t)buf.st_size);
    buffer[nb] = '\0';

    if (check_all(buffer, nb) == 1) {
        free(buffer);
        return (1);
    }
    free(buffer);
    return (0);
}

int error_handling(int ac, char **av)
{
    int fd;
    struct stat buf;

    if (ac != 2)
        return (1);
    stat(av[1], &buf);
    if (S_ISREG(buf.st_mode)) {
        if ((fd = open(av[1], O_RDONLY)) == -1)
            return (1);
    } else
        return (1);
    if (read_map_error(fd, av) == 1)
        return (1);
    return (0);
}