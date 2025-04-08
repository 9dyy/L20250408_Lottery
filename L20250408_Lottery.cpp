#include <iostream>
#include <Windows.h>

using namespace std;

struct FVector2D
{
    int X;
    int Y;
};

void GotoXY(FVector2D* NewXY)
{
    COORD pos = { NewXY->X, NewXY->Y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    FVector2D* Position = new FVector2D;
    Position->X = 0;
    Position->Y = 0;

    while (1)
    {
        system("cls");
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (Position->Y > 0)
            {
                Position->Y--;
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            Position->Y++;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            if (Position->X > 0)
            {
                Position->X--;
            }
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            Position->X++;
        }
        GotoXY(Position);
        cout << Position->X << "," << Position->Y;
        Sleep(5);
    }
    
    return 0;
}