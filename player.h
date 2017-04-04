// Cameron Taylor
// cdt0020
// 4/10/2016
// Compiled with eclipse and cygwin

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
