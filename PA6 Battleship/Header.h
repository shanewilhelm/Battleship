#ifndef HEADER_H
#define HEADER_H

#define MAX 10

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct stats
{
	int turns;
	int hits;
	int misses;
} Stats;


void welcome_screen (void);
int select_who_starts_first (void);
void initialize_game_board (char board[MAX][MAX], int rows, int columns);
void print_board (char board[MAX][MAX], int rows, int columns);
void manually_place_ships (char board[MAX][MAX], int rows, int columns);
int is_valid_placement (int prompt, char board[MAX][MAX], int rows, int columns, char ship_size, char orientation, char y, char x);
void randomly_place_ships (char board[MAX][MAX], int rows, int columns);
int check_shot (char target_board[MAX][MAX], int shot_y, int shot_x);
void update_hit_miss (char shot_board[MAX][MAX], char victim_board[MAX][MAX], int hit_or_miss, int shot_y, int shot_x);
void update_ship_health (char ship_hit, int ship_health[5]);
int which_ship_hit (char board[MAX][MAX], int shot_y, int shot_x, char ship_type[12]);
int is_victor (int p1_ship_health[5], int p2_ship_health[5]);
int is_sunk (char ship_hit, int ship_health[5]);
int is_repeat_shot (char shot_board[MAX][MAX], int shot_y, int shot_x);
int random_shot ();



#endif