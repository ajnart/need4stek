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

/* src/my_str_to_wordtab.c */
char **my_str_to_wordtab(char *str, char g);
/* src/n4s.c */
const char *send_cmd(char *command, ...);
void lidar_update(car_state_s *car_state);
void update_direction(car_state_s *car_st);
const char *forwards(car_state_s *car_state);
int main(void);

#endif