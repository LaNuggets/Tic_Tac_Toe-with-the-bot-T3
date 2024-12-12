#include "func.h"
#include <iostream>
#include <random>
#include <cstring>

struct S
{
    char grid[3][3];
};


bool isLegal(char grid[3][3], char move){
    int row = (move - '1') / 3;
    int col = (move - '1') % 3;
    return grid[row][col] != 'x' && grid[row][col] != 'o';
}


S doMove(char grid[3][3], char move){
    S res;
    memcpy(res.grid, grid, sizeof(res.grid));
    int row = (move - '1') / 3;
    int col = (move - '1') % 3;
    res.grid[row][col] = 'o';
    return res;
}


int Minimax(char grid[3][3], int deep, bool isMaxi){
    S g;
    if (deep == 0){
        return 0;
    }

    if(isMaxi){
        int bestValue = -10000;
        for (int i = 0; i <=9;++i){
            char move = '1'+i;
            if (isLegal(grid, move)){
                S newGrid = doMove(grid, move);
                int value = Minimax(newGrid.grid, deep-1, false);
                bestValue = std::max(bestValue, value);
                return bestValue;
            }
        }
    }else{
        int bestValue = 10000;
        for (int i = 0; i <=9;++i){
            char move = '1'+i;
            if (isLegal(grid, move)){
                S newGrid = doMove(grid, move);
                int value = Minimax(newGrid.grid, deep-1, true);
                bestValue = std::max(bestValue, value);
                return bestValue;
            }
        }
    }
    return 0;
}

char comp(char grid[3][3]){
    char bestPlay;
    S g;
    memcpy(g.grid, grid, sizeof(g.grid));
    int bestValue = 0;
    for (int i = 0; i <=9;++i){
            char move = '1'+i;
            if (isLegal(grid, move)){
                g = doMove(grid, move);
                int value = Minimax(g.grid, 100, false);
               if(value > bestValue){
                bestValue = value;
                bestPlay = move;
               }
            }
        }
    return bestPlay;
}



// char RandomMove(){
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(1, 9);
//     return '0'+dis(gen);
// }

// char finalBotPlay(char grid[3][3]){
//     char move=RandomMove();
//     if (isLegal(grid, move)){
//         return move;
//     }else{
//         return finalBotPlay(grid);
//     }
//     return 0;
// }

/*

All func needed :

MiniMax // Main logic the best move
GeneratePossibleMove // return a panel of move
ExecMove // return a new grid
main // compile all func

*/