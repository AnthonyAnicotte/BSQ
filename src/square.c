/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** Created by Anthony Anicotte,
*/

#include <stdlib.h>
#include "struct.h"
#include "function.h"

int between_dot(struct_t *structure)
{
    int i = structure->act_x;
    int j = structure->act_y;

    while (j <= structure->act_y + structure->offset) {
        while (i <= structure->act_x + structure->offset) {
            if (structure->tab[j][i] != '.')
                return (1);
            i++;
        }
        i = structure->act_x;
        j++;
    }
    return (0);
}

int check_square_offset(struct_t *structure)
{
    if (structure->tab[structure->act_y + structure->offset] != NULL) {
        if (structure->tab[structure->act_y + structure->offset][
            structure->act_x + structure->offset] == '.' &&
            structure->tab[structure->act_y][structure->act_x +
                structure->offset] == '.' && structure->tab[structure->act_y +
            structure->offset][structure->act_x] && between_dot(structure) == 0)
            return (0);
        else
            return (1);
    } else
        return (1);
}

void change_cos(struct_t *structure)
{
    structure->max_x = structure->act_x;
    structure->max_y = structure->act_y;
    structure->max_offset = structure->offset;
}

void is_a_dot(struct_t *structure)
{
    static int flag = 0;

    structure->offset = 1;
    while (check_square_offset(structure) == 0)
        structure->offset++;
    if (structure->offset > structure->max_offset) {
        change_cos(structure);
        flag = 1;
    } else if (structure->offset == structure->max_offset) {
        if (flag == 0) {
            change_cos(structure);
            flag = 1;
        } else if (structure->act_x < structure->max_x &&
            structure->act_y < structure->max_y)
            change_cos(structure);
    }
}

void find_square(struct_t *structure)
{
    while (structure->tab[structure->act_y] != NULL) {
        if (structure->tab[structure->act_y][structure->act_x] == '\0' ||
            structure->act_x + structure->offset >= structure->column ||
            structure->act_y + structure->offset >= structure->line) {
            structure->act_x = 0;
            structure->act_y++;
        } else if (structure->tab[structure->act_y][structure->act_x] == '.') {
            is_a_dot(structure);
            structure->act_x++;
        } else
            structure->act_x++;
    }
}