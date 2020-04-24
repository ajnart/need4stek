/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** nfs.h
*/

#ifdef __DEBUG__
#undef __DEBUG__
#define __DEBUG__ 1
#else
#define __DEBUG__ 0
#endif

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

#endif