/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** nfs.h
*/

#ifdef DEBUG
#undef DEBUG
#define DEBUG 1
#else
#define DEBUG 0
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

#endif