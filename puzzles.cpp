// Cameron Taylor
// cdt0020
// 4/10/2016
// Compiled with eclipse and cygwin

#include "puzzles.h"
#include "player.h"
#include<cstdlib>
using namespace std;

void make_puzzles(firstPuzzle& p_head)
{
	puzzlePtr curr;
	firstPuzzle puzzleList;
		p_head.puzzle_count = 6;
		p_head.first = new puzzle;
		curr = p_head.first;

		//1
		curr->question = "What character is the most frequently-portrayed character in the history of horror movies? \n1. Frakensien\n2. Van Helsing\n3. Dracula\n4. Jason\n5. Your mom\n";
		curr->answer = 3;
		curr->action_arr[0].type = reward;
		curr->action_arr[0].attribute = money;
		curr->action_arr[0].points = 10;

		curr->action_arr[1].type = penalty;
		curr->action_arr[1].attribute = money;
		curr->action_arr[1].points = -10;

		curr->action_arr[2].type = reward;
		curr->action_arr[2].attribute = time_left;
		curr->action_arr[2].points = -1;

		curr->action_arr[3].type = penalty;
		curr->action_arr[3].attribute = time_left;
		curr->action_arr[3].points = -2;

		curr->numOfActions = 4;
		curr->next = new puzzle;
		curr = curr->next;
		//2
		curr->question = "In the original Jackson family line up, how many brothers were there?\n1. 6\n2. 5\n3. 4\n4. 3 \n";
		curr->answer = 2;
		curr->action_arr[0].type = reward;
		curr->action_arr[0].attribute = money;
		curr->action_arr[0].points = 5;

		curr->action_arr[1].type = penalty;
		curr->action_arr[1].attribute = money;
		curr->action_arr[1].points = -5;

		curr->action_arr[2].type = reward;
		curr->action_arr[2].attribute = time_left;
		curr->action_arr[2].points = -1;

		curr->action_arr[3].type = penalty;
		curr->action_arr[3].attribute = time_left;
		curr->action_arr[3].points = -1;

		curr->numOfActions = 4;
		curr->next = new puzzle;
		curr = curr->next;

		//3
		curr->question = "What is Batman's real name? \n1. Batman\n2. Josh Lampert\n3. Bruce Wayne\n4. Bob the builder\n";
		curr->answer = 3;
		curr->action_arr[0].type = reward;
		curr->action_arr[0].attribute = money;
		curr->action_arr[0].points = 10;

		curr->action_arr[1].type = penalty;
		curr->action_arr[1].attribute = money;
		curr->action_arr[1].points = -10;

		curr->action_arr[2].type = reward;
		curr->action_arr[2].attribute = time_left;
		curr->action_arr[2].points = -1;

		curr->action_arr[3].type = penalty;
		curr->action_arr[3].attribute = time_left;
		curr->action_arr[3].points = -2;

		curr->numOfActions = 4;
		curr->next = new puzzle;
		curr = curr->next;
		//4
		curr->question = "The Wicked Queen gives Snow White what to render her comatose? \n1. an apple\n2. a pear\n3. a needle\n4. a stick\n";
		curr->answer = 1;
		curr->action_arr[0].type = reward;
		curr->action_arr[0].attribute = money;
		curr->action_arr[0].points = 10;

		curr->action_arr[1].type = penalty;
		curr->action_arr[1].attribute = money;
		curr->action_arr[1].points = -10;

		curr->action_arr[2].type = reward;
		curr->action_arr[2].attribute = time_left;
		curr->action_arr[2].points = -1;

		curr->action_arr[3].type = penalty;
		curr->action_arr[3].attribute = time_left;
		curr->action_arr[3].points = -2;

		curr->numOfActions = 4;
		curr->next = new puzzle;
		curr = curr->next;

		// 5
		curr->question = "On which street was the New York Stock Exchange established? \n1. main\n2. wall\n3. north\n4. fifth\n ";
		curr->answer = 2;
		curr->action_arr[0].type = reward;
		curr->action_arr[0].attribute = money;
		curr->action_arr[0].points = 10;

		curr->action_arr[1].type = penalty;
		curr->action_arr[1].attribute = money;
		curr->action_arr[1].points = -10;

		curr->action_arr[2].type = reward;
		curr->action_arr[2].attribute = time_left;
		curr->action_arr[2].points = -1;

		curr->action_arr[3].type = penalty;
		curr->action_arr[3].attribute = time_left;
		curr->action_arr[3].points = -2;

		curr->numOfActions = 4;
		curr->next = new puzzle;
		curr = curr->next;

		// 6
		curr->question = "In the Superman movies what newspaper does Clark Kent Work for?\n1. pizza palace\n2. times\n3. the daily planet\n4. Newspapers?\n";
		curr->answer = 3;
		curr->action_arr[0].type = reward;
		curr->action_arr[0].attribute = money;
		curr->action_arr[0].points = 10;

		curr->action_arr[1].type = penalty;
		curr->action_arr[1].attribute = money;
		curr->action_arr[1].points = -10;

		curr->action_arr[2].type = reward;
		curr->action_arr[2].attribute = time_left;
		curr->action_arr[2].points = -1;

		curr->action_arr[3].type = penalty;
		curr->action_arr[3].attribute = time_left;
		curr->action_arr[3].points = -2;

		curr->numOfActions = 4;
		curr->next = NULL;
}
void ask_puzzle(player& player, firstPuzzle p_head)
{
	u_short userAnswer;
	action_t player_gets;
	u_short puzzleSelect = rand()%6;
	puzzlePtr curr = p_head.first;
	for (int i = 0; i < puzzleSelect && curr != NULL; i++)
	{
		curr = curr->next;
	}
	cout << curr->question;
	cout << "\nChoose wisely: ";
	cin >> userAnswer;
	if (userAnswer == curr->answer)
	{
		cout << "Correct!\n";
		player_gets = reward;
	}
	else
	{
		cout << "Incorrect, better luck next time!\n";
		player_gets = penalty;
	}
	action actionForPuzzle;
	for (int i = 0; i < curr->numOfActions; i++)
	{
		if (curr->action_arr[i].type == player_gets)
		{
			actionForPuzzle = curr->action_arr[i];
			int pointNum = 0;
			pointNum = actionForPuzzle.points;
			if (player_gets == reward)
				{
					cout << "Reward: " << actionForPuzzle.points;
				}
				else
				{
					cout << "Penalty: " << (actionForPuzzle.points * -1);
				}
				switch (actionForPuzzle.attribute)
				{
					case money:
						cout << ".00 dollars\n";
						player.money += actionForPuzzle.points;
						break;
					case time_left:
						cout << " units of time\n";
						player.time += actionForPuzzle.points;
						break;
					case intelligence:
						cout << " intelligence\n";
						player.intelligence += actionForPuzzle.points;
						break;
					}
		}
	}

}
