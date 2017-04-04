// Cameron Taylor
// cdt0020
// 4/10/2016
// Compiled with eclipse and cygwin

#ifndef ____puzzles__
#define ____puzzles__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "player.h"
using namespace std;

enum attribute_t {money, time_left, intelligence};
enum action_t    {penalty, reward};
const int  MAX_ACTION_NUM = 4;


typedef unsigned short u_short;
struct action
{
    string  answer;
    action_t type;
    attribute_t attribute;
    u_short points;
};
struct puzzle
{
    string  question;
    u_short answer;
    u_short numOfActions;
    puzzle *next;
    action action_arr[MAX_ACTION_NUM];
};
typedef puzzle* puzzlePtr;
struct firstPuzzle
{
	u_short puzzle_count;
	puzzlePtr first;
};
void make_puzzles(firstPuzzle& p_head);
void ask_puzzle(player& player, firstPuzzle p_head);
#endif
