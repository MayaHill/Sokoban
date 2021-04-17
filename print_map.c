/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** print_map.c
*/

#include "include/sokoban.h"
#include "include/my.h"
#include "include/my_printf.h"

int get_longest_line(char **array)
{
    int max_len = 0;
    int len = 0;

    for (int i = 0; array[i]; i++) {
        len = my_strlen(array[i]);
        if (len > max_len)
            max_len = len;
    }
    return (max_len);
}

int can_print_map(char **map, int max_x, int new_y)
{
    if (new_y <= 0)
        return (1);
    for (int i = 0; map[i]; i++)
        if (max_x - my_strlen(map[i]) <= 0)
            return (1);
    return (0);
}

void print_centered_map(char **map, int max_x, int new_y)
{
    int max_len = get_longest_line(map);

    for (int i = 0; map[i]; i++)
        mvprintw((new_y / 2) + i, (max_x - max_len) / 2, map[i]);
}

void print_map(char **map)
{
    int max_x = 0;
    int max_y = 0;
    int new_y = 0;
    char *str = "Please resize the window";

    getmaxyx(stdscr, max_y, max_x);
    new_y = max_y - my_strlen_array(map);
    refresh();
    clear();
    if (can_print_map(map, max_x, new_y)) {
        mvprintw(max_y / 2, (max_x - my_strlen(str)) / 2, str);
    } else {
        print_centered_map(map, max_x, new_y);
    }
}