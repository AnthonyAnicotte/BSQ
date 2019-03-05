/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2018
** File description:
** Created by Anthony Anicotte,
*/

#include "function.h"
#include "struct.h"

void init_error_struct(error_struct_t *error_struct)
{
    error_struct->total_char = 0;
    error_struct->start = 0;
    error_struct->sure_line = 0;
    error_struct->first_line_len = 1;
}

void init_variables(error_struct_t *error_struct, char *buffer)
{
    while (buffer[error_struct->start] != '\n' &&
        buffer[error_struct->start] != '\0')
        error_struct->start++;
    error_struct->i = error_struct->start + 1;
    while (buffer[error_struct->i] != '\n' && buffer[error_struct->i] != '\0') {
        error_struct->first_line_len++;
        error_struct->i++;
    }
    error_struct->j = error_struct->start + 1;
    while (buffer[error_struct->j] != '\0') {
        if (buffer[error_struct->j] == '\n')
            error_struct->sure_line++;
        error_struct->j++;
    }
    error_struct->k = error_struct->start + 1;
    while (buffer[error_struct->k] != '\0') {
        error_struct->k++;
        error_struct->total_char++;
    }
}