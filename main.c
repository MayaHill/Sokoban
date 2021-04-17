/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** main.c
*/

#include "include/sokoban.h"
#include "include/my.h"
#include "include/my_printf.h"

int print_help(void)
{
    my_printf("USAGE\n    ./my_sokoban map\n");
    my_printf("DESCRIPTION\n    map file representing the warehouse");
    my_printf(" map, containing '#' for walls,\n");
    my_printf("         'P' for the player, 'X' for boxes");
    my_printf(" and 'O' for storage locations.\n");
    return (0);
}

int end_loop(int status, char **map, char **dup_map)
{
    print_map(map);
    refresh();
    clear();
    endwin();
    for (int i = 0; map[i]; i++) {
        free(map[i]);
        free(dup_map[i]);
    }
    free(map);
    free(dup_map);
    return (status);
}

int main_loop(char **map)
{
    char **dup_map = duplicate_map(map);
    char c;
    int status = 0;

    while (1) {
        print_map(map);
        status = game_won(map, dup_map);
        if (status != 2)
            return (end_loop(status, map, dup_map));
        c = getch();
        if (c == 32)
            return (main_loop(dup_map));
        else
            get_move_action(c, dup_map, map);
    }
    end_loop(0, map, dup_map);
}

int main(int argc, char **argv)
{
    char *str = NULL;
    char **map = NULL;

    if (argc != 2)
        return (84);
    if (my_strcmp(argv[1], "-h") == 0)
        return (print_help());
    str = read_file(argv[1]);
    if (str == NULL || check_map_error(str))
        return (84);
    map = my_str_to_word_array(str, "\n");
    free(str);
    if (map == NULL)
        return (84);
    initscr();
    noecho();
    curs_set(FALSE);
    return (main_loop(map));
}
