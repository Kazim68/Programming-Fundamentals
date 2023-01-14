#include <iostream>
#include <windows.h>
using namespace std;

void printMaze();
char getCharAtxy(short int x, short int y);
void printpacman(int x, int y);
void clear(int x, int y, char prev);
void erase(int x, int y);
void gotoxy(int x, int y);
void printghost1(int x, int y);
void printghost2(int x, int y);
void printscore(int score);

int main()
{

    int x = 4;
    int y = 4;
    bool gamerunning = true;
    int score = 0;
    int gx1 = 4;
    int gy1 = 22;
    int gx2 = 54;
    int gy2 = 10;
    string hdirection = "right";
    string vdirection = "up";
    char hprevchar = ' ';
    char vprevchar = ' ';

    system("cls");
    printMaze();
    printpacman(x, y);
    printghost1(gx1, gy1);
    printghost2(gx2, gy2);
    printscore(score);

    while (gamerunning)
    {
        Sleep(100);

        if (hdirection == "right")
        {
            char nextlocation = getCharAtxy(gx1 + 1, gy1);
            if (nextlocation == '|')
            {
                hdirection = "left";
            }
            else if (nextlocation == ' ' || nextlocation == '.')
            {
                clear(gx1, gy1, hprevchar);
                gx1 += 1;
                printghost1(gx1, gy1);
                hprevchar = nextlocation;
            }
        }
        if (hdirection == "left")
        {
            char nextlocation = getCharAtxy(gx1 - 1, gy1);
            if (nextlocation == '|')
            {
                hdirection = "right";
            }
            else if (nextlocation == ' ' || nextlocation == '.')
            {
                clear(gx1, gy1, hprevchar);
                gx1 -= 1;
                printghost1(gx1, gy1);
                hprevchar = nextlocation;
            }
        }

        if (vdirection == "up")
        {
            char nextlocation = getCharAtxy(gx2, gy2 - 1);
            if (nextlocation == '#')
            {
                vdirection = "down";
            }
            else if (nextlocation == ' ' || nextlocation == '.')
            {
                clear(gx2, gy2, vprevchar);
                gy2 -= 1;
                vprevchar = nextlocation;
                printghost2(gx2, gy2);
            }
        }
        if (vdirection == "down")
        {
            char nextlocation = getCharAtxy(gx2, gy2 + 1);
            if (nextlocation == '#')
            {
                vdirection = "up";
            }
            else if (nextlocation == ' ' || nextlocation == '.')
            {
                clear(gx2, gy2, vprevchar);
                gy2 += 1;
                vprevchar = nextlocation;
                printghost2(gx2, gy2);
            }
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            char nextlocation = getCharAtxy(x - 1, y);
            if (nextlocation == ' ')
            {
                erase(x, y);
                x -= 1;
                printpacman(x, y);
            }
            else if (nextlocation == '.')
            {
                erase(x, y);
                x -= 1;
                score += 1;
                printpacman(x, y);
                printscore(score);
            }
            else if (nextlocation == 'G')
            {
                gamerunning = false;
            }
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            char nextlocation = getCharAtxy(x + 1, y);
            if (nextlocation == ' ')
            {
                erase(x, y);
                x += 1;
                printpacman(x, y);
            }
            else if (nextlocation == '.')
            {
                erase(x, y);
                x += 1;
                score += 1;
                printpacman(x, y);
                printscore(score);
            }
            else if (nextlocation == 'G')
            {
                gamerunning = false;
            }
        }

        if (GetAsyncKeyState(VK_UP))
        {
            char nextlocation = getCharAtxy(x, y - 1);
            if (nextlocation == ' ')
            {
                erase(x, y);
                y -= 1;
                printpacman(x, y);
            }
            else if (nextlocation == '.')
            {
                erase(x, y);
                y -= 1;
                score += 1;
                printpacman(x, y);
                printscore(score);
            }
            else if (nextlocation == 'G')
            {
                gamerunning = false;
            }
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            char nextlocation = getCharAtxy(x, y + 1);
            if (nextlocation == ' ')
            {
                erase(x, y);
                y += 1;
                printpacman(x, y);
            }
            else if (nextlocation == '.')
            {
                erase(x, y);
                y += 1;
                score += 1;
                printpacman(x, y);
                printscore(score);
            }
            else if (nextlocation == 'G')
            {
                gamerunning = false;
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gamerunning = false;
        }
    }

    return 0;
}

void printMaze()
{
    cout << "##########################################################################           " << endl;
    cout << "||............................................................  .....   ||           " << endl;
    cout << "||..  %%%%%%%%%%%%%%%%%       ...      %%%%%%%%%%%%%%   |%|..   %%%%%   ||           " << endl;
    cout << "||..         |%|    |%|    |%|...     |%|          |%|  |%|..     |%|   ||           " << endl;
    cout << "||..         |%|    |%|    |%|...     |%|          |%|  |%|..     |%|   ||           " << endl;
    cout << "||..         %%%%%%%%%  .. |%|...     %%%%%%%%%%%%%%%      ..   %%%%%.  ||           " << endl;
    cout << "||..         |%|        .. |%|...    ................  |%| ..        .  ||           " << endl;
    cout << "||..         %%%%%%%%%%%.. |%|...    %%%%%%%%%%%%%     |%| ..   %%%%%.  ||           " << endl;
    cout << "||..                 |%|.            |%|.......        |%| ..     |%|.  ||           " << endl;
    cout << "||..     ........... |%|.            |%|.......|%|         ..     |%|.  ||           " << endl;
    cout << "||..|%|  |%|%%%%%|%|.|%|. |%|           .......|%|         ..|%|  |%|.  ||           " << endl;
    cout << "||..|%|  |%|     |%|..    %%%%%%%%%%%%  .......|%|          .|%|.       ||           " << endl;
    cout << "||..|%|  |%|     |%|..          ...|%|      %%%%%%         . |%|.       ||           " << endl;
    cout << "||..|%|              .          ...|%|                 |%| ..|%|.       ||           " << endl;
    cout << "||..|%|  %%%%%%%%%%%%%%%%       ...|%|%%%%%%%%%%%%     |%| ..|%|%%%%%%  ||           " << endl;
    cout << "||..................................................   |%| ...........  ||           " << endl;
    cout << "||   ...............................................         ........   ||           " << endl;
    cout << "||..|%|  |%|     |%|..    %%%%%%%%%%%%  .......|%|     |%| ..|%|.       ||           " << endl;
    cout << "||..|%|  |%|     |%|..          ...|%|      %%%%%%     |%| ..|%|.       ||           " << endl;
    cout << "||..|%|              .          ...|%|                 |%| ..|%|.       ||           " << endl;
    cout << "||..|%|  %%%%%%%%%%%%%%%        ...|%|%%%%%%%%%%%      |%| ..|%|%%%%%   ||           " << endl;
    cout << "||.................................................    |%| ..........   ||           " << endl;
    cout << "||   ..............................................          ........   ||           " << endl;
    cout << "##########################################################################           " << endl;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void erase(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void clear(int x, int y, char prev)
{
    gotoxy(x, y);
    cout << prev;
}

void printpacman(int x, int y)
{
    gotoxy(x, y);
    cout << "P";
}

void printghost1(int x, int y)
{
    gotoxy(x, y);
    cout << "G";
}

void printghost2(int x, int y)
{
    gotoxy(x, y);
    cout << "G";
}

void printscore(int score)
{
    gotoxy(100, 15);
    cout << "score: " << score;
}