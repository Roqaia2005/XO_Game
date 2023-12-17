#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include "BoardGame_Classes.hpp"
using namespace std;
tictactoeBoard::tictactoeBoard() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}
bool tictactoeBoard::update_board(int x, int y, char mark) {
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == ' ')) {
        board[x][y] = mark;
        n_moves++;
        return true;
    }
    return false;
}

void tictactoeBoard::display_board() {
    for (int i = 0; i < n_rows; i++) {
        cout << "\n";
        for (int j = 0; j < n_cols; j++) {
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n";
        for (int j = 0; j < n_cols; j++) {
            cout << "----";
        }
    }
    cout << endl;
}
bool tictactoeBoard::is_winner() {
    for (int i = 0; i < n_rows; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board[i][4])
            return true;

        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i])
            return true;
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] == board[4][4])
        return true;

    if (board[0][4] != ' ' && board[0][4] == board[1][3] && board[0][4] == board[2][2] && board[0][4] == board[3][1] && board[0][4] == board[4][0])
        return true;

    return false;
}
bool tictactoeBoard::is_draw() {
    return (n_moves == n_rows * n_cols);
}

bool tictactoeBoard::game_is_over() {
    return is_winner() || is_draw();
}









