#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int readlength()
{
    int num;
    cin >> num;
    return num;
}

int readnumber()
{
    int num;
    do
    {
        cin >> num;
    } while (!(num >= 1 && num <= 3));

    return num;
}

int random(int from, int to)
{
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}

enum engame
{
    stone = 1,
    paper,
    scissors
};

enum enwinner
{
    computer = 1,
    player,
    No_winner
};

enwinner check_winner(engame ch_of_player, engame ch_of_computer)
{
    if (ch_of_computer == ch_of_player)
    {
        return enwinner::No_winner;
    }
    else if (ch_of_computer == engame::paper && ch_of_player == engame::scissors)
    {
        return enwinner::player;
    }
    else if (ch_of_computer == engame::scissors && ch_of_player == engame::paper)
    {
        return enwinner::computer;
    }
    else if (ch_of_computer == engame::scissors && ch_of_player == engame::stone)
    {
        return enwinner::player;
    }
    else if (ch_of_computer == engame::stone && ch_of_player == engame::scissors)
    {
        return enwinner::computer;
    }
    else if (ch_of_computer == engame::paper && ch_of_player == engame::stone)
    {
        return enwinner::computer;
    }
    else if (ch_of_computer == engame::stone && ch_of_player == engame::paper)
    {
        return enwinner::player;
    }
}

string printwinner(enwinner result)

{
    switch (result)
    {
    case enwinner::computer:
        return "computer";
    case enwinner::player:
        return "player";

    case enwinner::No_winner:
        return "No winner";
    }
}

void counter_of_results(int &player_won_times, int &computer_won_times, int &draw_times, enwinner result)
{
    if (printwinner(result) == "computer")
    {
        computer_won_times++;
    }
    else if (printwinner(result) == "player")
    {
        player_won_times++;
    }
    else
    {
        draw_times++;
    }
}

string final_winner(int &player_won_times, int &computer_won_times)
{
    if (player_won_times == computer_won_times)
    {
        return "[No winner]";
    }
    else if (player_won_times > computer_won_times)
    {
        return " player ";
    }
    else
        return "computer";
}

string en_to_str(engame choice)
{
    switch (choice)
    {
    case engame::paper:
        return "paper";
    case engame::scissors:
        return "scissors";
    case engame::stone:
        return "stone";
    }
}

void rounds(int &player_won_times, int &computer_won_times, int &draw_times)
{
    int length;
    cout << " How many rounds 1 to 10 \n";
    length = readlength();
    enwinner result;
    for (int i = 1; i <= length; i++)
    {
        cout << " Round[" << i << "] begins :\n ";
        cout << " your choice is [1]stone  ,[2]paper,[3]scissors  ?    ";
        int num = readnumber();
        engame ch_of_player, ch_of_computer;
        ch_of_player = engame(num);
        ch_of_computer = engame(random(1, 3));
        enwinner result = check_winner(ch_of_player, ch_of_computer);

        cout << "-----------Round[" << i << "]----------------------\n";
        cout << "player choice   :" << en_to_str(ch_of_player) << "\n";
        cout << "computer choice :" << en_to_str(ch_of_computer) << "\n";

        cout << " round winner: " << printwinner(result) << "\n";
        counter_of_results(player_won_times, computer_won_times, draw_times, result);

        cout << "--------------------------------------------------------\n\n";
    }
    cout << "                    --------------------------------------------------------\n";
    cout << "                                        ***Game Over***                        \n";
    cout << "                    --------------------------------------------------------\n";
    cout << "                     ************************[Game Results]*********************\n";
    cout << "                     Game rounds     : " << length << "\n";
    cout << "                     player won times: " << player_won_times << "\n";
    cout << "                     computer won times:" << computer_won_times << "\n";
    cout << "                     Draw times      : " << draw_times << "\n";
    cout << "                     Final winner      : " << final_winner(player_won_times, computer_won_times);
}

// bool play_again()

int main()
{
    int player_won_times = 0, computer_won_times = 0, draw_times = 0;
    rounds(player_won_times, computer_won_times, draw_times);
}