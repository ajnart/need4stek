/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** n4s.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "nfs.h"
#include <stdarg.h>
#include <stdio.h>

const char *send_command(char *command)
{
    static char buffer[512];
    if (DEBUG) {
        dprintf(2, command);
    }
    dprintf(1, command);
    read(0, buffer, 512);
    return (buffer);
}

int n4s()
{
    send_command("START_SIMULATION\n");
    send_command("CAR_FORWARD:0.5\n");
    char *words, *string;
    string = strdup("Hello there, peasants!");
    int windex = 0;
    while ( (*(words+windex) = strsep(&string," ")) != NULL)
        windex++;
    return (0);
}