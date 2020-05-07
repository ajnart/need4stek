/*
** EPITECH PROJECT, 2019
** Test of
** File description:
** Tests Critérions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "nfs.h"

// ? Sending commands
const char *send_cmd(char *command, ...);
char **my_str_to_wordtab(char *str, char g);
void update_direction(car_state_s *car_st);
const char *forwards(int distance);

Test(send, send_cmd_dbg)
{
    cr_redirect_stdout();
    freopen((const char * restrict)"START_SIMULATION\n", "r", stdin);
    send_cmd("START_SIMULATION\n");
    cr_assert_stdout_eq_str("START_SIMULATION\n");
}

Test(send, send_cmd_2)
{
    cr_redirect_stdout();
    freopen((const char * restrict)"END_SIMULATION\n", "r", stdin);
    send_cmd("END_SIMULATION\n");
    cr_assert_stdout_eq_str("END_SIMULATION\n");
}

Test(lib, str_to_worldtab)
{
    char **comp = my_str_to_wordtab("4:5", ':');
    cr_assert_str_eq(comp[0], "4");
}

Test(main, forwards_2500)
{
    cr_redirect_stdout();
    freopen((const char * restrict)"CAR_FORWARD:1.0\n", "r", stdin);
    forwards(2500);
    cr_assert_stdout_neq_str("CAR_FORWARD:0.5\n");
}

Test(main, forwards_1200)
{
    cr_redirect_stdout();
    freopen((const char * restrict)"CAR_FORWARD:0.5\n", "r", stdin);
    forwards(1200);
    cr_assert_stdout_neq_str("CAR_FORWARD:0.7\n");
}

Test(main, direction)
{
    cr_redirect_stdout();
    car_state_s car_state = {200, 0, 2000, 0, 0};
    freopen((const char * restrict)"CAR_FORWARD:-0.2\n", "r", stdin);
    update_direction(&car_state);
    cr_assert_stdout_neq_str("CAR_FORWARD:-0.2\n");
}

Test(main, direction_2)
{
    cr_redirect_stdout();
    car_state_s car_state = {0, 200, 2000, 0, 0};
    freopen((const char * restrict)"WHEELS_DIR:0.3\n", "r", stdin);
    update_direction(&car_state);
    cr_assert_stdout_neq_str("WHEELS_DIR:0.3\n");
}

Test(main, lidar_1)
{
    cr_redirect_stdout();
    car_state_s car_state = {0, 200, 2000, 0, 0};
    freopen((const char * restrict)"WHEELS_DIR:0.3\n", "r", stdin);
    lidar_update(&car_state);
    cr_assert_stdout_neq_str("WHEELS_DIR:0.3\n");
}

Test(main, lidar_2)
{
    cr_redirect_stdout();
    car_state_s car_state = {0, 200, 2000, 0, 0};
    freopen((const char * restrict)"\n", "r", stdin);
    lidar_update(&car_state);
    cr_assert_stdout_neq_str("WHEELS_DIR:0.3\n");
}