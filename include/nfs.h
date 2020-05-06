/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** nfs.h
*/

#ifndef __NFS__
#define __NFS__

typedef struct n4s_infos {
    int ended;
    int obstructed;
    int front;
    int left;
    int right;
} car_state_s;

int n4s();
char **my_str_to_wordtab(char *str, char g);
void lidar_update(car_state_s *car_state);

#endif