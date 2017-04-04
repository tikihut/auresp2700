// Cameron Taylor
// cdt0020
// 4/10/2016
// Compiled with eclipse and cygwin

#include "project1_test.h"
#include "time.h"
#include <cstdlib>
using namespace std;

#define MAX_PUZZLES 6
//#define UNIT_TEST


int main()
{
#ifdef UNIT_TEST
    test_init_player();
    test_print_stats();
    test_print_options();
    test_add_score();
    test_main_menu();
    test_calc_score();
    test_view_scores();
#else
    srand(time(0));
    string name;
    cout << "\nWhat is your name? ";
    cin >> name;

    welcome(name);

    string score_file = "scores.txt";
    scoreboard scoreboard;
    int scores = load_scores(scoreboard, score_file);
    int choice = menu_driver(scoreboard);
    if (choice == 0)
    {
        return 0;
    }
    else
    {
        char choice;
        int  alive_status = 0;
        player player;
        initialize_player(player);
        int steps = 20;
        
        encounter_t encounter;
        
        cout << "\nBrace yourself, for the halls are dark and full of terrors.\nEntering the Dungeon... \n\n";
        print_stats(player);
        cout << "\n";
        while (alive_status < 1 && steps != 0)
        {
            print_steps(steps);
            cout << "Time left: " << player.time << ".\n\n";
            print_player_options();
            puzzle* puzzles;
            int puzzle_count = 6;
            cout << "\n\tPlease choose and action: ";
            cin >> choice;
            cout << endl;
            
            switch (choice)
            {
                case '1':
                    encounter = get_encounter();
                    do_encounter(encounter, player, puzzles, puzzle_count, steps);
                    break;
                case '2':
                    read_papers(player);
                    break;
                case '3':
                    search_for_change(player);
                    break;
                case '4':
                    print_stats(player);
                    break;
                case '5':
                    cout << "You quit... Get good kid...\n";
                    return 0;
                default:
                    cout << "Invalid choice, Try again!\n\n";
                    break;
            }
            cout << endl << endl;
            alive_status = is_player_alive(player);
        }
        
        if (steps == 0)
        {
            cout << "**** Gratz! ****\n"
            << "You win!\n\n";
            int final_score = calculate_score(player);
            cout << "Your score of " << final_score << " will be saved!\nThanks for playing!\n\n";
            score_node player_score;
            player_score.name  = name;
            player_score.score = final_score;
            add_score(scoreboard, player_score);
            save_scores(scoreboard, "scores.txt");
        }
        else
        {
            display_death(alive_status);
        }

    }
#endif
    return 0;
}
