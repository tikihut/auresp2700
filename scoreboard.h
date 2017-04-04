//Mitchell Derisio
//mhd0006
//4/03/2017

#ifndef ____scoreboard__
#define ____scoreboard__

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
struct score_node
{
    string name;
    unsigned int score;
    score_node* next;
};

typedef score_node* score_ptr;
typedef unsigned short u_short;

struct scoreboard
{
    u_short num_scores;
    score_ptr first;
};
int  load_scores(scoreboard& s_board, string filename);
void view_scores(scoreboard  s_board);
int  save_scores(scoreboard  s_board, string filename);
int  add_score  (scoreboard& s_board, score_node new_score);

#endif
