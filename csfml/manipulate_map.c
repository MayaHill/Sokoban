/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** get_map_coords.c
*/

#include "include/bonus_sokoban.h"

int *return_index(char **map, int x, char c, int *coords)
{
    for (int y = 0; map[x][y]; y++)
        if (map[x][y] == c) {
            coords[0] = x;
            coords[1] = y;
            return (coords);
        }
    return (coords);
}

int *get_index(char **map, char c)
{
    int *coords = malloc(sizeof(int) * 2);

    coords[0] = 0;
    coords[1] = 0;
    for (int x = 0; map[x]; x++)
        coords = return_index(map, x, c, coords);
    return (coords);
}

char **duplicate_map(char **map)
{
    int len = my_strlen_array(map);
    char **dup_map = malloc(sizeof(char *) * (len + 1));

    dup_map[len] = NULL;
    for (int i = 0; map[i]; i++)
        dup_map[i] = my_strdup(map[i]);
    return (dup_map);
}

int walkable(char c)
{
    if (c == '#' || c == 'X')
        return (0);
    if (c == 'O' || c == ' ')
        return (1);
    return (2);
}

int check_map_error(char *str)
{
    int nb_player = 0;
    int nb_blocks = 0;
    int nb_circles = 0;

    for (int i = 0; str[i]; i++) {
        if (walkable(str[i]) == 2 && str[i] != '\n' && str[i] != 'P') {
            my_printf("Unknown character: '%c'\n", str[i]);
            return (1);
        }
        if (str[i] == 'P')
            nb_player += 1;
        if (str[i] == 'X')
            nb_blocks += 1;
        if (str[i] == 'O')
            nb_circles += 1;
    }
    if (nb_player != 1 || nb_blocks != nb_circles)
        return (1);
    return (0);
}