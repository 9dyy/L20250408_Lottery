#include <iostream>
#include <random>

#define LOTTERYMAX 45

using namespace std;

int Numbers[LOTTERYMAX] = {};

void Init();
int RandNum();
void Shuffle();

int main()
{
    Init();
    Shuffle();
    for (int i = 0; i < 6; i++)
    {
        cout << Numbers[i] << " ";
    }

    return 0;
}

void Init()
{
    for (int i = 0; i < LOTTERYMAX; i++)
    {
        Numbers[i] = i + 1;
    }
}

int RandNum()
{
    // int형 1 ~ 45까지 중 랜덤 정수 (1, 45포함)
    static mt19937 gen = mt19937((unsigned int)time(NULL));
    static uniform_int_distribution<> dist(1, LOTTERYMAX);
    return dist(gen);
}

void Shuffle()
{
    for (int i = 0; i < LOTTERYMAX * 10000; i++)
    {
        int a = RandNum() - 1;
        int b = RandNum() - 1;
        int temp = Numbers[a];
        Numbers[a] = Numbers[b];
        Numbers[b] = temp;
    }
}
