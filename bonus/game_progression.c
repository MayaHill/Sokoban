/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** game_progression.c
*/

#include "include/bonus_sokoban.h"

int check_walls(char **map, int x, int y, int cpt)
{
    if (cpt == 2) {
        if (!walkable(map[x][y + 1]) && !walkable(map[x][y - 1]))
            return (1);
        if (!walkable(map[x + 1][y]) && !walkable(map[x - 1][y]))
            return (1);
    }
    return (0);
}

void block_is_stuck(char **map, int *coords, int *nb_blocks, int *nb_stuck)
{
    int cpt = 0;
    int x = coords[0];
    int y = coords[1];

    if (map[x][y] == 'X') {
        (*nb_blocks) += 1;
        if (!walkable(map[x + 1][y]))
            cpt++;
        if (!walkable(map[x - 1][y]))
            cpt++;
        if (!walkable(map[x][y + 1]))
            cpt++;
        if (!walkable(map[x][y - 1]))
            cpt++;
        if (check_walls(map, x, y, cpt))
            return;
        if (cpt >= 2)
            (*nb_stuck) += 1;
    }
}

int game_won(char **map, char **dup_map)
{
    int *coords = get_index(map, 'O');
    int *player_coords = get_index(map, 'P');
    int nb_blocks = 0;
    int nb_stuck = 0;

    if (!coords[0] && !coords[1] && map[0][0] != 'O')
        if (dup_map[player_coords[0]][player_coords[1]] != 'O')
            return (0);
    for (int x = 0; map[x]; x++)
        for (int y = 0; map[x][y]; y++) {
            coords[0] = x;
            coords[1] = y;
            block_is_stuck(map, coords, &nb_blocks, &nb_stuck);
        }
    free(coords);
    free(player_coords);
    if (nb_blocks == nb_stuck)
        return (1);
    return (2);
}