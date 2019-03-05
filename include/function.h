/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** Created by Anthony Anicotte,
*/
#ifndef PROJECT_FUNCTION_H
#define PROJECT_FUNCTION_H

#include "struct.h"

int error_handling(int ac, char **av);
void find_square(struct_t *structure);
void collect_map(struct_t *structure, char **av);
int get_start(char *buffer);
void fill_the_map(struct_t *structure);
void print_tab(char **tab, int col);
void init_error_struct(error_struct_t *error_struct);
void init_variables(error_struct_t *error_struct, char *buffer);


#endif