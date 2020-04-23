/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** n4s.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include "nfs.h"

const char *send_command(char *command, ...)
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
	response = send_command("GET_INFO_LIDAR\n");
    tab = my_str_to_wordtab((char *)response, ':');
    car_state->left = atof(tab[3]);
    car_state->front = atof(tab[18]);
    car_state->right = atof(tab[33]);
    if (__DEBUG__)
    dprintf(2, "[DEBUG] Sensors:\nFront: %d\tRight: %d\tLeft: %d\n",
        car_state->front, car_state->right, car_state->left);
}
// TODO : Free

void update_direction(car_state_s *car_st)
{
    char *dir = NULL;
    car_st->obstructed = car_st->front < 220 ? 1 : 0;
	if (car_st->front >= 1500)
		dir = strdup("0.005\n");
	else if (car_st->front >= 1000)
		dir = strdup("0.05\n");
	else if (car_st->front >= 600)
		dir = strdup("0.1\n");
	else if (car_st->front >= 400)
		dir = strdup("0.2\n");
	else if (car_st->front >= 200)
		dir = strdup("0.3\n");
	else if (car_st->front <= 200)
		dir = strdup("0.5\n");

    char buf[32];
	float nbr = car_st->left - car_st->right;

	((nbr > 0.0 && car_st->obstructed) || (nbr < 0.0 && !car_st->obstructed)) ?
    send_command("WHEELS_DIR:-%s", dir) : send_command("WHEELS_DIR:%s", dir);
}
// TODO : Fix norme.
// char *forwards(int distance)
// {

//     int i = 0;
//     float dis_list[6] = {4000, 2000, 1500, 1000, 600, 400};
//     float speed[6] = {1.0, 0.8, 0.5, 0.4, 0.2, 0.1};
//     while (dis_list[i] > distance)
//         i++;
//     send_command("CAR_FORWARD:%f\n", speed[i]);
// }

char *forwards(int distance)
{
	if (distance >= 1500)
		return("CAR_FORWARD:1.0\n");
    else if (distance >= 1300)
		return("CAR_FORWARD:0.8\n");
	else if (distance >= 900)
		return("CAR_FORWARD:0.5\n");
	else if (distance >= 600)
		return("CAR_FORWARD:0.4\n");
	else if (distance >= 400)
		return("CAR_FORWARD:0.2\n");
	else
		return("CAR_FORWARD:0.1\n");
}
// TODO : Norme

void main_loop()
{
    const char *response = NULL;
    car_state_s car_state = {0, 0, 2000, 0, 0};
	while (car_state.ended == 0) {
        if (car_state.obstructed)
            send_command("CAR_BACKWARDS:0.25\n");
        else
            response = send_command(forwards(car_state.front));
        if (strstr(response, "Track Cleared")) {
            car_state.ended = 1;
            dprintf(2, "[DEBUG] FIN !!!!\n");
            send_command("CAR_BACKWARDS:1\n");
            break;
        }
        lidar_update(&car_state);
        update_direction(&car_state);
	}
}
// TODO : Clear debug info
int n4s()
{
    send_command("START_SIMULATION\n");
    main_loop();
    send_command("END_SIMULATION\n");
    return (0);
}