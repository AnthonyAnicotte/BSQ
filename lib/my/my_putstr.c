/*
** EPITECH PROJECT, 2019
** PROJECT
** File description:
** Created by Anthony Anicotte,
*/

#include <unistd.h>

void my_putstr(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    write(1, str, (size_t)i);
}
