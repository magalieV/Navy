/*
** EPITECH PROJECT, 2019
** minishell.h
** File description:
** minishell.h
*/

#include "my.h"
#include "get_next_line.h"

#include <sys/stat.h>
#include <fcntl.h>

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#ifndef	S_TIME
#define	S_TIME 1000
#endif

#ifndef NAVI_H_
#define NAVI_H_

int player_a(char *path, char **map[2]);
int player_b(int pid, char *path, char **map[2]);

int get_pid_user(void);
int get_msg(int pid);
int send_msg(int pid, int msg);

int destroy_map(char **map[2]);
int craft_map(char *path, char **map[2]);
int craft_navy(char **map[2], char uff[8]);
int craft_map_navy_one(char uff[8], char **map[2]);
int craft_map_navy_two(char uff[8], char **map[2]);
int eq_int_in_array(int idx, int ref[], int end);
int display_map(char **map[2]);

int wait_answer(void);
int answer(int pid);

int win(int pid, char **map[2], int w_value[2]);
int do_turn(int pid, char **map[2], int w_value[2], int n);
int play_turn(int pid, char **map[2], int w_value[2], int n);


int end_game(int pid, char **map[2], int w_value[2]);
int player_b(int pid, char *path, char **map[2]);
int player_a(char *path, char **map[2]);

int size_chip(char **map[2], char ref);
#endif
