/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** read_file.c
*/

#include "include/sokoban.h"
#include "include/my.h"
#include "include/my_printf.h"

int my_strlen_array(char **array)
{
    int len = 0;

    for (; array[len]; len++);
    return (len);
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