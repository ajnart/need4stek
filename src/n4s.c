/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** n4s.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "nfs.h"

const char *send_cmd(char *command, ...)
{
    va_list argptr;
    va_start(argptr, command);
    static char buffer[512];
    vdprintf(1, command, argptr);
    buffer[read(0, buffer, 512)] = '\0';
    if (strstr(buffer, "Track Cleared"))
        va_arg(argptr, int *)[0] = 1;
    va_end(argptr);
    return (buffer);
}

void lidar_update(car_state_s *car_state)
{
    const char *response;
    static char **tab;
    int i = 0;
    response = send_cmd("GET_INFO_LIDAR\n", &car_state->ended);
    tab = my_str_to_wordtab((char *)response, ':');
    if (tab[34]) {
        car_state->left = atof(tab[3]);
        car_state->front = atof(tab[15]);
        car_state->right = atof(tab[34]);
    }
    for (i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void update_direction(car_state_s *car_st)
{
    char *dir = NULL;
    int i = 0;
    float distance[8] = {2500, 1500, 900, 600, 400, 200, 50, 0};
    float dirs[8] = {0.0, 0.05, 0.1, 0.12, 0.15, 0.25, 0.4};
    int comp = car_st->left - car_st->right;

    car_st->obstructed = car_st->front < 150 || car_st->left <= 20 ||
    car_st->right <= 20 ? 1 : 0;
    for (i = 0; distance[i] >= car_st->front; i++);
    if ((comp > 0 && car_st->obstructed) || (comp < 0 && !car_st->obstructed))
        send_cmd("WHEELS_DIR:-%.4f\n", dirs[i], &car_st->ended);
    else
        send_cmd("WHEELS_DIR:%.4f\n", dirs[i], &car_st->ended);
}

const char *forwards(car_state_s *car_state)
{
    int i = 0;
    float dis_list[6] = {2000, 1100, 800, 400, 200, 0};
    float speed[6] = {1, 0.8, 0.6, 0.3, 0.2, 0.1};
    while (dis_list[i] > car_state->front)
        i++;
    return(send_cmd("CAR_FORWARD:%.2f\n", speed[i], &car_state->ended));
}

#ifndef __TESTS
int main(void)
{
    car_state_s car_state = {0, 0, 3000, 0, 0};
    send_cmd("START_SIMULATION\n", &car_state.ended);
    const char *response = NULL;
    while (car_state.ended == 0) {
        if (car_state.obstructed)
            send_cmd("CAR_BACKWARDS:0.3\n", &car_state.ended);
        else
            response = forwards(&car_state);
        lidar_update(&car_state);
        update_direction(&car_state);
    }
    send_cmd("END_SIMULATION\n");
    return (0);
}
#endif