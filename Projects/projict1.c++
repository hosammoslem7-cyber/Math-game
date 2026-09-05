#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

enum engame
{
    stone = 1,
    paper,
    scissors
};

enum enwinner
{
    player = 1,
    computer,
    no_winner
};

struct str_roundinfo
{
    short round_game;
    engame ch_of_player;
    engame ch_of_computer;
    enwinner winner;
    string winner_name;
};

struct st_gameresults
{
    short player_win_times;
    short computer_win_times;
    short draw_times;
    short num_of_rounds;
    string winner_name;
};

short read_num_of_rounds()
{
    short num;
    do
    {
        cout << "How many rounds 1 to 10\n";
        cin >> num;
    } while (!(num >= 1 && num <= 10));

    return num;
}

int random(int from, int to)
{
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}

engame read_player()
{
    int num;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> num;
    } while (!(num >= 1 && num <= 3));

    return engame(num);
}

engame get_computer_choice()

{
    int num;
    do
    {
        num = random(1, 3);
    } while (!(num >= 1 && num <= 3));

    return engame(num);
}

enwinner who_win_round(str_roundinfo round_info)
{
    if (round_info.ch_of_computer == round_info.ch_of_player)
    {
        return enwinner::no_winner;
    }
    switch (round_info.ch_of_player)
    {
    case engame::paper:
        if (round_info.ch_of_computer == engame::scissors)

        {
            return enwinner::computer;
        }
        break;
    case engame::scissors:
        if (round_info.ch_of_computer == engame::stone)
        {
            return enwinner::computer;
        }
        break;

    case engame::stone:
        if (round_info.ch_of_computer == engame::paper)
        {
            return enwinner::computer;
        }
        break;
    }
    return enwinner::player;
}

string winnername(enwinner winner)
{
    string arrwinnername[3] = {"player", "computer", "no winner"};
    return arrwinnername[winner - 1];
}

string choicename(engame choice)
{
    string arrchoice[3] = {
        " stone",
        "paper",
        "scissors"};
    return arrchoice[choice - 1];
}

void print_results(str_roundinfo round_info)
{
    cout << "\n-----------Round[" << round_info.round_game << "]------------\n";
    cout << " player choice :" << choicename(round_info.ch_of_player) << "\n";
    cout << "computer choice :" << choicename(round_info.ch_of_computer) << "\n";
    cout << "Round winner: " << winnername(round_info.winner) << "\n";
    cout << "------------------------------------------------------------\n";
}

string who_win_game(st_gameresults Results)
{
    if (Results.player_win_times > Results.computer_win_times)
        return "player";
    if (Results.computer_win_times > Results.player_win_times)
        return "computer";
    else
        return "no winner";
}

st_gameresults fill_game_results(short player_win_times, short computer_win_times, short draw_times, short num_of_rounds)
{
    st_gameresults results;
    results.player_win_times = player_win_times;
    results.computer_win_times = computer_win_times;
    results.draw_times = draw_times;
    results.num_of_rounds = num_of_rounds;
    results.winner_name = who_win_game(results);
    return results;
}

st_gameresults playgame(short num_of_rounds)
{
    str_roundinfo round_info;
    short player_win_times = 0, computer_win_times = 0, draw_times = 0;
    for (int roundnum = 1; roundnum <= num_of_rounds; roundnum++)
    {
        cout << "Round[" << roundnum << "] begins\n";
        round_info.round_game = roundnum;
        round_info.ch_of_player = read_player();
        round_info.ch_of_computer = get_computer_choice();
        round_info.winner = who_win_round(round_info);
        round_info.winner_name = winnername(round_info.winner);

        if (round_info.winner == enwinner::computer)
        {
            computer_win_times += 1;
        }
        else if (round_info.winner == enwinner::player)
        {
            player_win_times += 1;
        }
        else
        {
            draw_times += 1;
        }
        print_results(round_info);
    }
    return fill_game_results(player_win_times, computer_win_times, draw_times, num_of_rounds);
}

void show_final_results(st_gameresults Results)
{
    cout << "Game Rounds :" << Results.num_of_rounds << "\n";
    cout << "player_win_times " << Results.player_win_times << "\n";
    cout << "computer_win_times " << Results.computer_win_times << "\n";
    cout << "draw_times   " << Results.draw_times << "\n";
    cout << "Final winner   :" << Results.winner_name << "\n";
}

void showgameover()
{
    cout << "                    --------------------------------------------------------\n";
    cout << "                                        ***Game Over***                        \n";
    cout << "                    --------------------------------------------------------\n";
    cout << "                     ************************[Game Results]*********************\n";
}
int main()
{
    srand((unsigned)time(NULL));
    st_gameresults Game_results = playgame(read_num_of_rounds());
    showgameover();
    show_final_results(Game_results);
}