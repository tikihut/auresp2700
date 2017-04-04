//Mitchell Derisio
//mhd0006
//4/03/2017

#include "player.h"
using namespace std;
void initialize_player(player& player)
{
    player.intelligence = 20;
    player.money        = 11;
    player.time         = 25;
    player.score        = 0;
}

void print_stats(player player)
{
    cout << "You have:\n\n"
    << "Intelligence: " << player.intelligence << endl
    << "Time: " << player.time  << endl
    << "Money: $" << player.money << ".00" << endl;
}

void print_player_options()
{
    cout <<
    "\t1) Move forward (takes time, could be risky…)\n"
    << "\t2) Read technical papers (boost intelligence, takes time)\n"
    << "\t3) Search for loose change (boost money, takes time)\n"
    << "\t4) View character\n"
    << "\t5) Quit the game\n\n";
}
