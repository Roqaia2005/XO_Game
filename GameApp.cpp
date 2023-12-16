#include <random>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include"BoardGame_Classes.hpp"
#include "Player.cpp"
#include "RandomPlayer.cpp"
#include "GameManager.cpp"
#include "Game1.cpp"
#include "Game2.cpp"
#include "Game3.cpp"
#include "X_O_Board.cpp"
int main(){

    int whichGame;
    cout<<"Enter 1 to play 3*3 XO Game \n"
          "2 to play  5 x 5 Tic Tac Toe Game , 3 to play Four-in-a-row Game , 4 to play 5 x 5 Tic Tac Toe ";
    cin>>whichGame;
    if (whichGame==1) {
        int choice1;
        Player* players1[2];
        players1[0] = new Player (1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice1;
        if (choice1 != 1)
            players1[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players1[1] = new RandomPlayer ('o', 3);

        GameManager game1 (new X_O_Board(), players1);
        game1.run();
        system ("pause");
    }
    else if(whichGame==2) {
        int choice2;
        Player *players2[2];
        players2[0] = new Player(1, 'x');

        cout << "Welcome to FCAI pyramic Tic Tac Toe Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice2;
        if (choice2 != 1)
            players2[1] = new Player(2, 'o');
        else

            players2[1] = new RandomPlayer('o', 3);

        GameManager game2(new Game1Board(), players2);
        game2.run();
        system("pause");

    }
    else if(whichGame==3) {
        int choice3;
        Player *players3[2];
        players3[0] = new cnct4_player(1, 'x');

        cout << "Welcome to FCAI Four-in-a-row  Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice3;
        if (choice3 != 1)
            players3[1] = new cnct4_player(2, 'o');
        else
            //Player pointer points to child
            players3[1] = (new random_cnct4_player('o', 7));

        GameManager game3(new connect_four_board(), players3);
        game3.run();
        system("pause");

    }
    else if(whichGame==4) {

        Player* players[2];

        int choice4;
        players[0] = new Player(1,'X');

        cout<<"Welcome to FCAI 5 x 5 Tic Tac Toe \n";
        cout << "Press 1 if you want to play with computer: ";
        cin>>choice4;
        tictactoeBoard board;
        if (choice4!=1){
            players[0] = new Player(2,'O');

        }
        else{
            players[1] = new RandomPlayer('O', 5);

        }




        GameManager game(&board, players);
        game.run();

        delete players[0];
        delete players[1];


    }
    else {
        cout << "Invalid Game Number";

    }
    }


