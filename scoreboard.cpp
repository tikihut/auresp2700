// Cameron Taylor
// cdt0020
// 4/10/2016
// Compiled with eclipse and cygwin

#include "scoreboard.h"
using namespace std;
int load_scores(scoreboard& s_board, string filename)
{
    ifstream file(filename.c_str());
    
    string name;
    int score;
    
    if ( !file.good())
    {
        cout << "Error loading scores!\n";
        return -1;
    }
    score_ptr root = new score_node;
    score_ptr curr;
    curr = root;
    s_board.num_scores = 0;
    
    while (file >> name >> score)
    {
        curr->name  = name;
        curr->score = score;
        curr->next  = new score_node;
        curr = curr->next;
        s_board.num_scores++;
    }
    
    curr->next = NULL;
    s_board.first = root;
    return 0;
}

void view_scores(scoreboard s_board)
{
    score_ptr curr;
    
    if (s_board.num_scores == 0)
    {
        cout << "There are no scores yet. You can't lose!!\n";
    }
    else
    {
        int TOP_SCORES = 10;
        int score_counter = 0;
        curr = s_board.first;
        int printscores = (s_board.num_scores < 10) ? s_board.num_scores : TOP_SCORES;
        
        cout << "The top " << printscores << " High Scores are:\n";
        
        while (curr != NULL && score_counter < TOP_SCORES)
        {
            cout << "\t" << curr->name << " " << curr->score << endl;
            
            if (curr->next->score == 0)
            {
                cout << "-no more scores to show-\n";
                break;
            }
            else
            {
                curr = curr->next;
                score_counter++;
            }
        }
    }
}

int save_scores(scoreboard s_board, string filename)
{
    ofstream scoresFile;
    scoresFile.open(filename.c_str());
    
    if (!scoresFile.good()) {
    	return -1;
    }
    score_ptr curr = s_board.first;

    while (curr != NULL)
    {
        scoresFile << curr->name << " " << curr->score << endl;
        curr = curr->next;
    }
    scoresFile.close();
    
    return 0;
}

int add_score(scoreboard& s_board, score_node new_score)
{
    score_ptr root = new score_node;
    
    if (new_score.score > s_board.first->score)
    {
        root          = &new_score;
        root->next    = s_board.first;
        s_board.first = root;
        s_board.num_scores++;
        
        return 1;
    }
    else
    {
        root = s_board.first;
        score_ptr curr, pre;
        curr = root;
        while (new_score.score < curr->score && curr != NULL)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = &new_score;
        new_score.next = curr;
        s_board.num_scores++;
        
        return 0;
    }
}
