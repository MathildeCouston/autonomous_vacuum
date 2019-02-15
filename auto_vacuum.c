/*
** EPITECH PROJECT, 2019
** auto_vaccum
** File description:
** automatic vacuum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

char or_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'N' || str[i] == 'E' ||
        str[i] == 'S' || str[i] == 'W')
        return (str[i]);
    }
    return (str[0]);
}

int next(char *str)
{
    char *new = NULL;
    int size = 1;
    int i = 0;

    for (; str[size - 1] != ' '; size++);
    new = malloc(sizeof(char) * size + 1);
    for (; str[size] != '\0'; size++) {
        new[i] = str[size];
        i++;
    }
    return (atoi(new));
}

int main(int ac, char **av)
{

    // variable declaration 

    size_t len = 0;
    char *line = NULL;
    int width = 0;
    int height = 0;
    int x = 0;
    int y = 0;
    char or;
    char *ins = NULL;


    // open the file for reading

    FILE *file = fopen(av[1], "r");


    // parsing file

    getline(&line, &len, file);
    width = atoi(line);
    height = next(line);
    free(line);
    getline(&line, &len, file);
    x = atoi(line);
    y = next(line);
    or = or_char(line);
    getline(&ins, &len, file);
    

    // processing instructions

    for (int i = 0; ins[i] != '\0'; i++) {
        if (ins[i] == 'D') {
            if (or == 'N')
                or = 'E';
            else if (or == 'E')
                or = 'S';
            else if (or == 'S')
                or = 'W';
            else if (or == 'W')
                or = 'N';
        } else if (ins[i] == 'A') {
            if (or == 'N')
                y++;
            else if (or == 'E')
                x++;
            else if (or == 'S')
                y--;
            else if (or == 'W')
                x--;
        } else if (ins[i] == 'G') {
            if (or == 'N')
                or = 'W';
            else if (or == 'W')
                or = 'S';
            else if (or == 'S')
                or = 'E';
            else if (or == 'E')
                or = 'N';
        }
    }


    // print final output

    printf("%d %d %c\n", x, y, or);
    return (0);
}
