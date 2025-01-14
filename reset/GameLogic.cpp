#include <iostream>
#include <string>
#include <vector>
#include "function.h"



int menu(){
    std::cout << "Welcome to this game of Tic Tac Toe against the T3 bot\n";
    return 0;
}

void userChoice(int &x, int &y){
    int userChoice;
    std::cout << "Choose your cell : ";
    std::cin >> userChoice;
    
    x = (userChoice-1)/3;
    y = (userChoice-1)%3;
}

void printBoard(const std::vector<std::vector<char>>& board){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool isLegal(const std::vector<std::vector<char>>& board, int x, int y){
    return board[x][y] != 'x' && board[x][y] != 'o';
}

bool isBoardFull(const std::vector<std::vector<char>>& board){
    int count = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if (board[i][j] == 'x' || board[i][j] == 'o'){
                count++;
            }
        }
    }
    if (count == 9){
        return true;
    }
    return false;
}

bool isWin(const std::vector<std::vector<char>>& board, char player){
        for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main(){
    std::vector<std::vector<char>> board = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    char player = 'x';
    menu();
    printBoard(board);

    int x,y;

    while(true){

        //User turn
        userChoice(x,y);
        if (!isLegal(board, x, y)){
            std::cout <<"This cell is already full";
            continue;
        }
        board[x][y] = player;
        printBoard(board);

        if(isWin(board, player)){
            std::cout <<"x Win !;\n";
            break;
        }

        if (isBoardFull(board)){
            std::cout <<"Draw\n";
            break;
        }

        std::cout << "\n";

        //Bot turn
        std::pair<int, int> bestMove = findBestMove(board);
        board[bestMove.first][bestMove.second] = 'o';

        printBoard(board);

        if(isWin(board, player)){
            std::cout <<"o Win !;\n";
            break;
        }

        if (isBoardFull(board)){
            std::cout <<"Draw\n";
            break;
        }
    }

    return 0;
}

