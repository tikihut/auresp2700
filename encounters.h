//Mitchell Derisio
//mhd0006
//4/03/2017

#ifndef ____encounters__
#define ____encounters__

#include <stdio.h>
#include <iostream>
#include "player.h"
#include "puzzles.h"

enum encounter_t {nothing, new_puzzle, professor, grad_student, grunt, papers};
encounter_t get_encounter();
void do_encounter(encounter_t type, player& player, puzzle* puzzles, int& i, int& steps);

#endif
