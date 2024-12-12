#include "func.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

struct R{
    char grid[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'}, 
        {'7', '8', '9'}
    };
    bool isXTurn = true;
};

int align(){
    std::cout << std::endl;
    return 0;
}

char AskUser(){
    char userChoice;
    while(true){
    std::cout << "Choose a number between 1 and 9: ";
    std::cin >> userChoice;
        if (userChoice >= '1' && userChoice <= '9') {
            return userChoice;
        } else {
            std::cout << "Invalid input." << std::endl;
        }
    }
}

int Display(char grid[3][3]){
    for (int i = 0; i < 3;++i){
        for (int j = 0; j < 3;++j){
            std::cout << " | " << grid[i][j] << " | ";
        }
        if (i < 2) {
            std::cout << "\n---------------------";
        }
         std::cout << std::endl;
    }
    return 0;
}


R Replace(char grid[3][3], char userChoice, bool isXTurn){
    for (int i = 0; i < 3;++i){
        for (int j = 0; j < 3;++j){
            if (grid[i][j] == userChoice){
                grid[i][j] = isXTurn ? 'x' : 'o';
            }
        }
    }
    R res;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            res.grid[i][j] = grid[i][j];
        }
    }
    res.isXTurn = !isXTurn;
    return res;
}

bool WinCondition(char grid[3][3],char player){
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (grid[0][j] == player && grid[1][j] == player && grid[2][j] == player) {
            return true;
        }
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
        return true;
    }
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) {
        return true;
    }
    return false;
}

bool EndGameScreen(bool isXTurn, char grid[3][3], bool gameFinished){
if (!isXTurn){
    if (WinCondition(grid, 'x')){
        std::cout << "X have win" << std::endl;
        gameFinished = true;
        exit(0);
    }
}else{
    if (WinCondition(grid, 'o')){
        std::cout << "O have win" << std::endl;
        gameFinished = true;
        exit(0);
    }
}
    return gameFinished;
}

int main() {
    int c = 0;
    bool gameFinished = false;
    R result;

    Display(result.grid);

    while (c < 9 && !gameFinished){
        align();
        char userChoice = AskUser();
        align();
        result = Replace(result.grid,userChoice,result.isXTurn);
        Display(result.grid);
        gameFinished =EndGameScreen(result.isXTurn, result.grid, gameFinished);
        c++;
        align();
        std::cout << "The bot think of the best move...";
        align();
        align();
        char botPlay = comp(result.grid);
        result = Replace(result.grid,botPlay,result.isXTurn);
        Display(result.grid);
        gameFinished =EndGameScreen(result.isXTurn, result.grid, gameFinished);
        c++;
    }
    if (!gameFinished){
         std::cout << "Draw" << std::endl;
    }
    return 0;
}
