#include <iostream>
#include <windows.h>
using namespace std;

void playermove(int x, int y);
void printMaze();
void gotoxy(int x, int y)
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int main(){

 int x = 3;
 int y = 2;

 system("cls");
 printMaze(); 
  
 while (true){

  if (y < 23) 
 {
 playermove(x, y);
 y += 1;
 }

 if (y == 23)
 {
 gotoxy(x, y-1);
 cout << " ";
 y = 2;
 x += 1;
 playermove(x, y);
 } 
}

 gotoxy(0, 30);
 return 0;}

void printMaze(){

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
cout << "||..|%|              .    G     ...|%|                 |%| ..|%|.       ||           " << endl;
cout << "||..|%|  %%%%%%%%%%%%%%%        ...|%|%%%%%%%%%%%      |%| ..|%|%%%%%   ||           " << endl;
cout << "||.................................................    |%| ..........   ||           " << endl;
cout << "||   ..............................................          ........   ||           " << endl;
cout << "##########################################################################           " << endl;
}


void playermove(int x, int y)
{
 gotoxy(x, y-1);
 cout << " "; 
 gotoxy(x, y);
 cout << "P"; 
 Sleep(100);
}







