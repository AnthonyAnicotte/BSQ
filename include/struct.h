/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** Created by Anthony Anicotte,
*/

#ifndef PROJECT_STRUCT_H
#define PROJECT_STRUCT_H

typedef struct struct_s
{
    char **tab;
    int line;
    int column;
    int total_char;
    int act_x;
    int act_y;
    int max_x;
    int max_y;
    int offset;
    int max_offset;

} struct_t;

typedef struct error_struct_s
{
    int i;
    int j;
    int k;
    int total_char;
    int start;
    int sure_line;
    int first_line_len;

} error_struct_t;

#endif
