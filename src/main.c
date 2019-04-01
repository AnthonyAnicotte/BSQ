/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include "function.h"
#include "struct.h"

int get_start(char *buffer)
{
    int cpt = 0;

    while (buffer[cpt] != '\n')
        cpt++;
    return (cpt + 1);
}

void init_struct(struct_t *structure)
{
    structure->line = 0;
    structure->column = 0;
    structure->total_char = 0;
    structure->act_x = 0;
    structure->act_y = 0;
    structure->max_x = 0;
    structure->max_y = 0;
    structure->offset = 1;
    structure->max_offset = 0;
}

void free_structure(struct_t *structure)
{
    for (int i = 0; structure->tab[i] != NULL; i++)
        free(structure->tab[i]);
    free(structure->tab);
    free(structure);
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) != 0)
        return (84);
    struct_t *structure = malloc(sizeof(struct_t));
    init_struct(structure);
    collect_map(structure, av);
    fill_the_map(structure);
    print_tab(structure->tab, structure->column);
    free_structure(structure);
}