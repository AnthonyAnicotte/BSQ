/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** Created by Anthony Anicotte,
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "function.h"

void fill_the_map(struct_t *structure)
{
    int line = structure->max_y;
    int col = structure->max_x;

    while (line != structure->max_y + structure->max_offset) {
        while (col != structure->max_x + structure->max_offset) {
            structure->tab[line][col] = 'x';
            col++;
        }
        col = structure->max_x;
        line++;
    }
}

void print_tab(char **tab, int col)
{
    for (int i = 0; tab[i] != NULL; i++) {
        tab[i][col - 1] = '\n';
        tab[i][col] = '\0';
        my_putstr(tab[i]);
    }
}

char **my_str_to_tab(char *buffer, struct_t *structure)
{
    char **tab = malloc(sizeof(char *) * (structure->line + 1));
    int cpt = 0;
    int i = get_start(buffer);
    int j = 0;

    while (buffer[i] != '\0') {
        tab[cpt] = malloc(sizeof(char) * structure->column + 2);
        while (buffer[i] != '\n') {
            tab[cpt][j] = buffer[i];
            i++;
            j++;
        }
        tab[cpt][j] = '\0';
        i++;
        j = 0;
        cpt++;
    }
    tab[cpt] = NULL;
    return (tab);
}

void collect_map(struct_t *structure, char **av)
{
    char *buffer;
    struct stat buf;
    int fd;
    int i;

    stat(av[1], &buf);
    buffer = malloc(sizeof(char) * buf.st_size + 1);
    fd = open(av[1], O_RDONLY);
    buffer[read(fd, buffer, (size_t)buf.st_size)] = '\0';
    i = get_start(buffer);
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            structure->line++;
        i++;
        structure->total_char++;
    }
    structure->column = structure->total_char / structure->line;
    structure->tab = my_str_to_tab(buffer, structure);
    find_square(structure);
    free(buffer);
}