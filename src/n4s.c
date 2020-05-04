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
    if (__DEBUG__)
        write(2, command, strlen(command));
    vdprintf(1, command, argptr);
    read(0, buffer, 512);
    va_end(argptr);
    return (buffer);
}

void lidar_update(car_state_s *car_state)
{
    const char *response;
    static char **tab;
    int i = 0;
    response = send_cmd("GET_INFO_LIDAR\n");
    tab = my_str_to_wordtab((char *)response, ':');
    car_state->left = atof(tab[3]);
    car_state->front = atof(tab[18]);
    car_state->right = atof(tab[33]);
    if (__DEBUG__)
        dprintf(2, "[DEBUG] Sensors:\nFront: %d\tRight: %d\tLeft: %d\n",
                car_state->front, car_state->right, car_state->left);
    for (i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void update_direction(car_state_s *car_st)
{
    char *dir = NULL;
    int i = 0;
    float distance[7] = {2000, 1500, 900, 600, 400, 200, 0};
    float dirs[7] = {0.005, 0.05, 0.1, 0.2, 0.25, 0.4};
    int comp = car_st->left - car_st->right;

    car_st->obstructed = car_st->front < 200 || car_st->left <= 0
        || car_st->right <= 0 ? 1 : 0;
    for (i = 0; distance[i] >= car_st->front; i++);
    if ((comp > 0 && car_st->obstructed) || (comp < 0 && !car_st->obstructed))
        send_cmd("WHEELS_DIR:-%.4f\n", dirs[i]);
    else
        send_cmd("WHEELS_DIR:%.4f\n", dirs[i]);
}

const char *forwards(int distance)
{
    int i = 0;
    float dis_list[6] = {2000, 1500, 1000, 600, 400, 0};
    float speed[6] = {1.0, 0.8, 0.5, 0.4, 0.2, 0.1};

    while (dis_list[i] > distance)
        i++;
    return(send_cmd("CAR_FORWARD:%.2f\n", speed[i]));
}

int n4s(void)
{
    send_cmd("START_SIMULATION\n");
    const char *response = NULL;
    car_state_s car_state = {0, 0, 2000, 0, 0};
    while (car_state.ended == 0) {
        if (car_state.obstructed)
            send_cmd("CAR_BACKWARDS:0.25\n");
        else
            response = forwards(car_state.front);
        if (strstr(response, "Track Cleared")) {
            car_state.ended = 1;
            send_cmd("CAR_BACKWARDS:0.5\n");
            break;
        }
        lidar_update(&car_state);
        update_direction(&car_state);
    }
    send_cmd("END_SIMULATION\n");
    return (0);
}