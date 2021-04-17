/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** read_file.c
*/

#include "include/bonus_sokoban.h"

int print_help(void)
{
    my_printf("USAGE\n    ./my_sokoban map\n");
    my_printf("DESCRIPTION\n    map file representing the warehouse");
    my_printf(" map, containing '#' for walls,\n");
    my_printf("         'P' for the player, 'X' for boxes");
    my_printf(" and 'O' for storage locations.\n");
    return (0);
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat s;
    char *buff;

    if (fd < 0)
        return (NULL);
    if (stat(filepath, &s) < 0)
        return (NULL);
    buff = malloc(s.st_size + 1);
    if (buff == NULL)
        return (NULL);
    buff[s.st_size] = 0;
    if (read(fd, buff, s.st_size) < 0)
        return (NULL);
    return (buff);
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
    srand(time(0));
    init_tiles(map);
    return (0);
}