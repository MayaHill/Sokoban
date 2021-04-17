/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** move_player.c
*/

#include "include/sokoban.h"
#include "include/my.h"

void edit_under_player(char **dup_map, char **map, int *save)
{
    map[save[0]][save[1]] = ' ';
    if (dup_map[save[0]][save[1]] == 'O')
        map[save[0]][save[1]] = 'O';
}

int check_valid_pos(char **map, int x, int y)
{
    int arr_len = my_strlen_array(map);

    if (x < 0 || y < 0 || x >= arr_len || y >= my_strlen(map[x]) - 1)
        return (1);
    return (0);
}

void move_player(char **map, char **dup_map, int x, int y)
{
    int *player = get_index(map, 'P');
    int valid = 1;

    if (check_valid_pos(map, player[0] + x, player[1] + y))
        valid = 0;
    if (valid && map[player[0] + x][player[1] + y] == 'X') {
        if (check_valid_pos(map, player[0] + x * 2, player[1] + y * 2))
            valid = 0;
        if (valid && walkable(map[player[0] + x * 2][player[1] + y * 2])) {
            edit_under_player(dup_map, map, player);
            map[player[0] + x][player[1] + y] = 'P';
            map[player[0] + x * 2][player[1] + y * 2] = 'X';
        }
    } else if (valid && walkable(map[player[0] + x][player[1] + y])) {
        edit_under_player(dup_map, map, player);
        map[player[0] + x][player[1] + y] = 'P';
    }
    free(player);
}

void get_move_action(char c, char **dup_map, char **map)
{
    if (c == 68)
        move_player(map, dup_map, 0, -1);
    if (c == 67)
        move_player(map, dup_map, 0, 1);
    if (c == 65)
        move_player(map, dup_map, -1, 0);
    if (c == 66)
        move_player(map, dup_map, 1, 0);
}