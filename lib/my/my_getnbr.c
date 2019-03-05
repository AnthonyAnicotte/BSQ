/*
** EPITECH PROJECT, 2018
** getnbr
** File description:
** task
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 0;
    int res = 0;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-') {
            i++;
            j++;
        } else if (str[i] == '+')
        i++;
        else
        return (0);
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = (res * 10) + (str[i] - 48);
        i++;
    }
    if (j % 2 == 1)
    return (-1 * res);
    return (res);
}
