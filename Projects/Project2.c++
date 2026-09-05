#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int readAnswer()
{
    int number;
    cin >> number;
    return number;
}

short read_num_of_questions()
{
    short num;
    do
    {
        cout << " how many questions do you want answer\n  ";

        cin >> num;

    } while (!(num >= 1 && num <= 10));
    return num;
}

short random(short from, short to)
{
    short randnum = rand() % (to - from + 1) + from;
    return randnum;
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

string level_name(enlevel level)
{
    string arrlevel[4] = {"Easy", "med", "hard", "mix"};
    return arrlevel[level - 1];
}

string operation_name(enoperation operation)
{
    string arroperation[5] = {"add", "sub", "mul", "divide", "mix"};
    return arroperation[operation - 1];
}

enlevel read_level()
{

    short num = 0;
    do
    {
        cout << " Enter Question level [1]]Easy  [2] med  [3] hard [4] mix\n";

        cin >> num;

    } while (!(num >= 1 && num <= 4));

    return enlevel(num);
}

enoperation read_operation()
{

    short num = 0;
    do
    {
        cout << " Enter operation type [1] add  [2] sub  [3] mul [4] divide  [5]Mix\n";

        cin >> num;

    } while (!(num >= 1 && num <= 5));

    return enoperation(num);
}

struct stQuestion
{

    int num1 = 0;
    int num2 = 0;
    int correctAnswer = 0;
    int playerAnswer = 0;
    bool AnswerResult = 0;
    enoperation optype;
    enlevel Question_level;
};

struct stQuiz
{
    enoperation optype;
    enlevel Question_level;
    int wrong_answers = 0;
    int right_answers = 0;
    stQuestion Question_list[100];
    int num_of_questions = 0;
    bool pass = 0;
};

int simple_calculator(int &num1, int &num2, enoperation optype)
{
    switch (optype)
    {
    case enoperation::add:
        return num1 + num2;
        break;

    case enoperation::sub:
        return num1 - num2;
        break;

    case enoperation::mul:
        return num1 * num2;
        break;

    case enoperation::divide:
        return num1 / num2;
        break;
    default:
        return num1 + num2;
    }
}

stQuestion Generate_Question(enoperation optype, enlevel level)
{
    stQuestion Quuestion;
    if (enlevel::mix == level)
        level = enlevel(random(1, 3));
    if (enoperation::Mix == optype)
        optype = enoperation(random(1, 4));

    Quuestion.optype = optype;
    switch (level)
    {
    case enlevel::Easy:
        Quuestion.num1 = random(1, 10);
        Quuestion.num2 = random(1, 10);
        break;
    case enlevel::med:
        Quuestion.num1 = random(10, 99);
        Quuestion.num2 = random(10, 99);
        break;
    case enlevel::hard:
        Quuestion.num1 = random(100, 200);
        Quuestion.num2 = random(100, 200);
        break;
    }
    Quuestion.correctAnswer = simple_calculator(Quuestion.num1, Quuestion.num2, Quuestion.optype);
    return Quuestion;
}

void Generate_Quiz(stQuiz &Quiz)
{
    for (int i = 0; i < Quiz.num_of_questions; i++)
    {
        Quiz.Question_list[i] = Generate_Question(Quiz.optype, Quiz.Question_level);
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

    default:
        return '+';
    }
}

void printQuestions(stQuiz &Quiz, int &i)
{
    cout << "Question [" << i + 1 << "/" << Quiz.num_of_questions << "]\n";
    cout << Quiz.Question_list[i].num1 << "\n";
    cout << Quiz.Question_list[i].num2 << " ";
    cout << choice_operator(Quiz.Question_list[i].optype);
    cout << "\n----------------\n";
}

void correctAnswer(stQuiz &Quiz, int &i)
{
    if (Quiz.Question_list[i].playerAnswer != Quiz.Question_list[i].correctAnswer)
    {
        Quiz.Question_list[i].AnswerResult = false;
        Quiz.wrong_answers++;
        cout << "Wrong answer\n";
        cout << "The Right answer is " << Quiz.Question_list[i].correctAnswer << "\n";
    }
    else
    {
        Quiz.Question_list[i].AnswerResult = true;
        Quiz.right_answers++;
        cout << "Right answer\n";
    }
}

void AskAndCorrectQuestionListAnswers(stQuiz &Quiz)
{
    for (int i = 0; i < Quiz.num_of_questions; i++)
    {
        printQuestions(Quiz, i);
        Quiz.Question_list[i].playerAnswer = readAnswer();
        correctAnswer(Quiz, i);
    }
    Quiz.pass = (Quiz.right_answers >= Quiz.wrong_answers);
}

string Finalresult(bool pass)
{
    if (pass)
    {
        return "Pass";
    }
    else
        return "Fail";
}

void show_a_final_results(stQuiz &Quiz)
{
    cout << "\n------------------------------------------\n";
    cout << " Final results is " << Finalresult(Quiz.pass);
    cout << "\n------------------------------------------\n";
    cout << "num_of_questions   :" << Quiz.num_of_questions << "\n";
    cout << "level    :" << level_name(Quiz.Question_level) << "\n";
    cout << "op_type   :" << operation_name(Quiz.optype) << "\n";
    cout << "num_of_right_answers     :" << Quiz.right_answers << "\n";
    cout << "num_of_wrong_answers   :" << Quiz.wrong_answers << "\n";
}

void play_game()
{
    stQuiz Quiz;
    Quiz.num_of_questions = read_num_of_questions();
    Quiz.Question_level = read_level();
    Quiz.optype = read_operation();
    Generate_Quiz(Quiz);
    AskAndCorrectQuestionListAnswers(Quiz);
    show_a_final_results(Quiz);
}

int main()
{
    srand((unsigned)time(NULL));

    play_game();
}
