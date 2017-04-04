// Cameron Taylor
// cdt0020
// 4/10/2016
// Compiled with eclipse and cygwin

#ifndef ____menu__
#define ____menu__

#include <stdio.h>
#include <iostream>
#include "player.h"
#include "scoreboard.h"
using namespace std;
void welcome(string name);
void main_menu();
int calculate_score(player player);
int menu_driver(scoreboard s_board);
int is_player_alive(player player);
void display_death(int type);
void print_steps(int steps);
void print_time(int time);
void read_papers(player& player);
void search_for_change(player& player);

#endif
