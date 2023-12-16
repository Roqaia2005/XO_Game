#include <random>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include"BoardGame_Classes.hpp"
// implement pyramic Tic Tac Toe Game
using namespace std;
Game1Board::Game1Board () {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++){
           board[i][j]=' '; 

        }
            
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Game1Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (((x == 0 && y == 2) || (x == 1 && y == 1) || (x == 1 && y == 2) || (x == 1 && y == 3) || 
    (x == 2 && y == 0) || (x == 2 && y == 1) ||
     (x == 2 && y == 2) || (x == 2 && y == 3) || (x == 2 && y == 4) )&& board[x][y] == ' ') {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}


void Game1Board::display_board() {
    cout << setw(28) << "|(0, 2) " << board[0][2] << '|' << endl;
    cout << setw(29) << "----------" << endl;
    cout << "         |(1, 1) " << board[1][1] << "|(1, 2) " << board[1][2] << "|(1, 3) " << board[1][3] << '|' <<  endl;
    cout << "         ----------------------------" << endl;
    cout << "|(2, 0) " << board[2][0] << "|(2, 1) " << board[2][1] << "|(2, 2) "
     << board[2][2] << "|(2, 3) " << board[2][3] << "|(2, 4) " << board[2][4] << '|' << endl;
    cout << "----------------------------------------------" << endl;
}

bool Game1Board::is_winner() {
    if((board[0][2]==board[1][2]&&board[1][2]==board[2][2]&&board[0][2]!=' '&&board[1][2]!=' '&&board[2][2]!=' ')||
    (board[1][1]==board[1][2]&&board[1][2]==board[1][3]&&board[1][1]!=' '&&board[1][2]!=' '&&board[1][3]!=' ')||
    (board[2][0]==board[2][1]&&board[2][1]==board[2][2]&&board[2][0]!=' '&&board[2][1]!=' '&&board[2][2]!=' ')
    ||(board[2][2]==board[2][3]&&board[2][3]==board[2][4]&&board[2][2]!=' '&&board[2][3]!=' '&&board[2][4]!=' ')
    ||(board[2][1]==board[2][2]&&board[2][2]==board[2][3]&&board[2][1]!=' '&&board[2][2]!=' '&&board[2][3]!=' ')
    ||(board[0][2]==board[1][3]&&board[1][3]==board[2][4]&&board[0][2]!=' '&&board[1][3]!=0&&board[2][4]!=' ')
    ||(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=' '&&board[1][1]!=' '&&board[2][0]!=' '))
    {
    return true;
}
return false;
    
    
 
}                                                                                                                                                                                                                   
// Return true if 9 moves are done and no winner
bool Game1Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Game1Board::game_is_over () {
    return n_moves >= 9;
}









