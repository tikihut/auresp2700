//Mitchell Derisio
//mhd0006
//4/03/2017

#include "encounters.h"
#include <stdlib.h>
#include "puzzles.h"
using namespace std;
encounter_t get_encounter()
{
    int ChanceOfEnc = rand() % 100;
    
    if (ChanceOfEnc <= 25) {
    	return nothing;
    } // 25%
    else if (ChanceOfEnc > 25 && ChanceOfEnc <= 55) {
    	return new_puzzle;
    } // 30%
    else if (ChanceOfEnc > 55 && ChanceOfEnc <= 65) {
    	return professor;
    } // 10%
    else if (ChanceOfEnc > 65 && ChanceOfEnc <= 75) {
    	return grad_student;
    } // 10%
    else if (ChanceOfEnc > 75 && ChanceOfEnc <= 90) {
    	return grunt;
    } // 15%
    else {
    	return papers;
    } // 10%
}

void do_encounter(encounter_t type, player& player, puzzle* puzzles, int& i, int& steps)
{
    unsigned short time_loss, intel_loss, int_gain, money_gain;
    firstPuzzle puzzleList;
    cout << "You move forward one step, and...\n\n";
    switch (type)
    {
        case nothing:
            cout << "Nothing happens!\nYou spent one unit of time.\n";
            steps -= 1;
            break;
            
        case new_puzzle:
            cout << "Puzzle: ";
            make_puzzles(puzzleList);
            ask_puzzle(player, puzzleList);
            steps -=1;
            break;
            
        case professor:
            time_loss  = (rand() % 3) + 1;
            int_gain = (rand() % 2);
            cout << "You encounter a professor.\n"
            << "You lose " << time_loss << " units of time and gain " << int_gain << " intelligence\n\n";
            player.time -= time_loss;
            player.intelligence += int_gain;
            steps -= 1;
            break;
            
        case grad_student:
            time_loss  = (rand() % 3) + 1; // Lose between 1 and 3 time
            cout << "You come across another grad student.\n"
            << "You lose " << time_loss << " units of time.\n\n";
            player.time -= time_loss;
            steps -= 1;
            break;

        case grunt:
            time_loss  = (rand() % 3) + 1;
            intel_loss = (rand() % 4) + 1;
            cout << "You complete some grunt work for another teacher!\n"
            << "The work makes you lose " << time_loss << " units of time and " << intel_loss << " intelligence! Sorry..\n\n";
            player.time -= time_loss;
            player.intelligence -= intel_loss;
            steps -= 1;
            break;

        case papers:
            time_loss  = (rand() % 3) + 1;
            money_gain = (rand() % 10) + 1;
            cout << "You find some papers to grade!\n"
            << "you spent " << time_loss << " units of time, but gained $" << money_gain << ".00!\n\n";
            player.time -= time_loss;
            player.money += money_gain;
            steps -= 1;
            break;
    }
}
