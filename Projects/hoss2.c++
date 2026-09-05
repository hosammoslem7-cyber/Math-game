#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

short random(short from, short to)
{
    short randnum = rand() % (to - from + 1) + from;
    return randnum;
}

short read_num_of_questions()
{
    cout << " how many questions do you want answer\n  ";
    short num;
    cin >> num;
    return num;
}

enum enlevel
{
    Easy = 1,
    med,
    hard,
    mix
};

enum enoperation
{
    add = 1,
    sub,
    mul,
    divide,
    Mix
};

enlevel read_level()
{
    cout << " Enter Question level [1]]Easy  [2] med  [3] hard [4] mix\n";

    short num;
    cin >> num;
    return enlevel(num);
}

enoperation read_operation()
{
    cout << " Enter operation type [1] add  [2] sub  [3] mul [4] divide  [5]Mix\n";

    short num;
    cin >> num;
    return enoperation(num);
}

struct st_final_results
{
    enlevel level;
    enoperation ch_of_op;
    short num_of_right_answers;
    short num_of_wrong_answers;
    short num_of_questions;
};

struct st_data
{
    enlevel level_type;
    enoperation operation_type;
    short num1;
    short num2;
    short result;
};

st_final_results Fill_results(short &num_of_questions, short &num_of_right_answers, short &num_of_wrong_answers, enoperation optype, enlevel leveltype)
{
    st_final_results results;
    results.level = leveltype;
    results.num_of_questions = num_of_questions;
    results.num_of_right_answers = num_of_right_answers;
    results.num_of_wrong_answers = num_of_wrong_answers;
    results.ch_of_op = optype;
    return results;
}

string level_name(enlevel level)
{
    string arrlevel[4] = {"Easy", "med", "hard", "mix"};
    return arrlevel[level - 1];
}

string operation_name(enoperation operation)
{
    string arroperation[5] = {"add", "sub", "mul","divide" ,"mix"};
    return arroperation[ operation-1];
}

void mapping_to_level_mix(st_data &data)
{

    switch (random(1, 3))
    {
    case 1:
        data.num1 = random(1, 10);
        data.num2 = random(1, 10);
        break;
    case 2:
        data.num1 = random(10, 99);
        data.num2 = random(1, 99);

        break;
    case 3:
        data.num1 = random(100, 200);
        data.num2 = random(100, 200);

        break;
    }
}

char mapping_to_operator()
{
    switch (random(1, 4))
    {
    case 1:
        return '+';
    case 2:
        return '-';

    case 3:
        return '*';

    case 4:
        return '/';
    }
}

char choice_operator(enoperation choice)
{
    switch (choice)
    {
    case enoperation::add:
        return '+';

    case enoperation::sub:
        return '-';
    case enoperation::mul:
        return '*';
    case enoperation::divide:
        return '/';
    case enoperation::Mix:
        return mapping_to_operator();
    }
}

void store_nums(enlevel level, st_data &data)
{
    switch (level)
    {

    case enlevel::Easy:
        data.num1 = random(1, 10);
        data.num2 = random(1, 10);

        break;
    case enlevel::med:
        data.num1 = random(10, 99);
        data.num2 = random(10, 99);
        break;
    case enlevel::hard:
        data.num1 = random(100, 200);
        data.num2 = random(100, 200);
        break;
    case enlevel::mix:
        mapping_to_level_mix(data);

        break;
    }
}

void print_nums(enoperation choice, st_data &data, char &value)
{

    cout << data.num1 << "\n";
    cout << value;
    cout << data.num2 << "\n";
}

void work_on_nums(enoperation type_operator, st_data &data)
{

    switch (type_operator)
    {
    case enoperation::add:
        data.result = data.num1 + data.num2;
        break;

    case enoperation::sub:
        data.result = data.num1 - data.num2;
        break;

    case enoperation::mul:
        data.result = data.num1 * data.num2;
        break;

    case enoperation::divide:
        data.result = data.num1 / data.num2;
        break;
    }
}

bool check_answer(st_data &data)
{

    short answer;
    cin >> answer;
    if (answer == data.result)
    {
        cout << " Right answer\n ";
        return true;
    }
    else 
    {
        cout << " wrong answer\n ";
        cout << " The  Right answer is   " << data.result << "\n";
        return false;
    }
}

void transfer_to_enum(char &op, st_data &data)
{
    switch (op)
    {
    case '+':
        data.operation_type = enoperation::add;
        break;

    case '-':
        data.operation_type = enoperation::sub;
        break;

    case '*':
        data.operation_type = enoperation::mul;
        break;

    case '/':
        data.operation_type = enoperation::divide;
        break;
    }
}

string P_F_or_Pass(st_final_results &Results)
{
    if (Results.num_of_right_answers > Results.num_of_wrong_answers)
        return " Pass ";
    else if(Results.num_of_right_answers==Results.num_of_wrong_answers)
        return " Draw ";
        else
        return "  Fail  ";
}

void show_a_final_sentence(st_final_results &Results)
{
    cout << "\n------------------------------------------\n";
    cout << " Final results is " << P_F_or_Pass(Results);
    cout << "\n------------------------------------------\n";
}

void show_final_results(st_final_results &game_results)
{
    cout << "num_of_questions   :" << game_results.num_of_questions << "\n";
    cout << "level    :" << level_name(game_results.level) << "\n";
    cout << "op_type   :" << operation_name(game_results.ch_of_op) << "\n";
    cout << "num_of_right_answers     :" << game_results.num_of_right_answers << "\n";
    cout << "num_of_wrong_answers   :" << game_results.num_of_wrong_answers << "\n";
}

st_final_results play_math_game(short& num_of_questions, st_data &data, st_final_results &Results)
{
    short num_of_right_answers = 0, num_of_wrong_answers = 0;
    for (int i = 1; i <= num_of_questions; i++)
    {
        bool is_mix = false;
        cout << " Questions [" << i << "/" << num_of_questions << "]\n";
        store_nums(data.level_type, data);
        char value;
        if (data.operation_type == enoperation::Mix)
        {
            value = choice_operator(data.operation_type);

            transfer_to_enum(value, data);
            is_mix = true;
        }
        if (!is_mix)
        {
            value = choice_operator(data.operation_type);
        }
        print_nums(data.operation_type, data, value);

        work_on_nums(data.operation_type, data);
        bool result_of_check = check_answer(data);
        if (result_of_check)
        {
            num_of_right_answers += 1;
        }
        else
        {
            num_of_wrong_answers += 1;
        }
        if (is_mix)
        {
            data.operation_type = enoperation::Mix;
        }
    }
    return Fill_results(num_of_questions, num_of_right_answers, num_of_wrong_answers, data.operation_type, data.level_type);
}

void start_game(st_data &data, st_final_results &Results)
{
    bool will_you_play;
    do
    {
        short num_of_questions = read_num_of_questions();
        data.level_type = read_level();
        data.operation_type = read_operation();

        st_final_results Final_results = play_math_game(num_of_questions, data, Results);
        P_F_or_Pass(Final_results);
        show_a_final_sentence(Final_results);
        show_final_results(Final_results);
        cout << " Do you want play again 1/0 \n";
        cin >> will_you_play;

    } while (will_you_play==1);
}

int main()
{
    st_data data;
    st_final_results Results;
    srand((unsigned)time(NULL));
    start_game(data, Results);
}