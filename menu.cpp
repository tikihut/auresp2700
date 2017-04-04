//Mitchell Derisio
//mhd0006
//4/03/2017

#include "menu.h"
#include <cstdlib>
using namespace std;
void welcome(string name)
{
    cout <<
    "\n==================================================================\n|"
    << "                        Welcome, " << name << "                            |" << endl
    << "==================================================================\n\n";
}

void main_menu()
{
    cout
    << "1) Start a New Game of Dragons!\n"
    << "2) View the top 10 High Scores\n"
    << "3) Quit\n\n";
}

int calculate_score(player player)
{
    return player.intelligence*player.time*player.money;
}

int menu_driver(scoreboard s_board)
{
    char player_choice;
    while (true)
    {
        main_menu();
        cout << "\tPlease choose an option: ";
        cin >> player_choice;
        switch (player_choice)
        {
            case '1':
                return 1;
            case '2':
                cout << endl;
                view_scores(s_board);
                break;
            case '3':
            	cout << "Exiting game...";
                return 0;
                break;
            default:
                cout << "INVALID Please select a valid option!!\n";
                break;
        }
        cout << endl << endl;
    }
}

int is_player_alive(player player)
{
    if (player.time <= 0) {
    	return 1; }
    if (player.intelligence <= 0) {
    	return 2; }
    if (player.money <= 0) {
    	return 3; }
    return 0;
}

void display_death(int type)
{
    switch (type)
    {
        case 1:
            cout << "You are late for class. You Lose!\n";
            break;
        case 2:
            cout << "You ran out of intelligence! You Lose!\n";
            break;
        case 3:
            cout << "You ran out of money! You Lose!\n";
            break;
    }
}

void print_steps(int steps)
{
    cout << "You are " << steps << " steps away from the goal. ";
}

void read_papers(player& player)
{
    int intel_gain = ( rand() % 5 ) + 1;
    player.time -= 2;
    player.intelligence += intel_gain;
    cout << "You read through some technical papers. You gain " << intel_gain << " intelligence, but\nlose 2 units of time.\n";
}


void search_for_change(player& player)
{
    int money_gain = ( rand() % 5 ) + 1;
    player.time -= 2;
    player.money += money_gain;
    cout << "You search around for some change...\n\n"
    << "You gain $" << money_gain << " but, lose 2 units of time!\n";
}
