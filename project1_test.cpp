// Cameron Taylor
// cdt0020
// 4/10/2016
// Compiled with eclipse and cygwin

#include "project1_test.h"
using namespace std;

void test_init_player()
{
    player player;
    initialize_player(player);
    cout << "\nTesting initialize_player...\n";
    assert(player.intelligence == 20);
    assert(player.money == 11);
    assert(player.time == 25);
    cout << "initialize_player successful!\n\n";
}

void test_print_stats()
{
    player player;
    initialize_player(player);
    cout << "Testing print_stats...\n\n";
    print_stats(player);
    cout << "\nprint_stats successful!\n\n";
}
void test_print_options()
{
    cout << "Testing print_player_options...\n\n";
    print_player_options();
}

void test_main_menu()
{
    cout << "\nTesting main_menu...\n\n";
    main_menu();
}

void test_calc_score()
{
    cout << "Testing calculate_scores...\n";
    player new_player;

    new_player.time = 10;
    new_player.money = 10;
    new_player.intelligence = 10;
    assert (calculate_score(new_player) == 1000);
    cout << "\nPassed!\n";
}
void test_view_scores()
{
    scoreboard tsco;
    assert(load_scores(tsco, "test_scores.txt") == 0);
    cout << "Testing view_scores...\n";
    view_scores(tsco);
}
void test_add_score()
{
    scoreboard s_board;
    int load = load_scores(s_board, "test_scores.txt");
    cout << "\nTesting add_score...\n";
    assert(s_board.num_scores == 3);
    cout << "Passed!\n";
    
    cout << "\nTesting adding test scores with two scores\n";
    
    score_node new_score1, new_score2;
    new_score1.name  = "Bob";
    new_score1.score = 300;
    
    new_score2.name  = "Jeff";
    new_score2.score = 20;
    
    int add1 = add_score(s_board, new_score1) ;
    int add2 = add_score(s_board, new_score2) ;
    assert( add1 == 1);
    assert( add2 == 0);
    assert( s_board.num_scores == 5);
    cout << "Passed!\n\n";
}
