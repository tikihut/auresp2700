//Mitchell Derisio
//mhd0006
//4/03/2017

#ifndef ____player__
#define ____player__

#include <stdio.h>
#include <iostream>

struct player
{
    int intelligence;
    int money;
    int time;
    int score;
};

void initialize_player(player& player);
void print_stats(player player);
void print_player_options();
#endif
