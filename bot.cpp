#include "func.h"
#include <iostream>
#include <random>
#include <cstring>
#include <climits>

struct S
{
    char grid[3][3];
};


bool isLegal(char grid[3][3], char move){
    int row = (move - '1') / 3;
    int col = (move - '1') % 3;
    return grid[row][col] != 'x' && grid[row][col] != 'o';
}

char changePlayer(char player){
    return (player == 'o') ? 'x' : 'o';
}


S doMove(char grid[3][3], char move, char player){
    S res;
    memcpy(res.grid, grid, sizeof(res.grid));
    int row = (move - '1') / 3;
    int col = (move - '1') % 3;
    res.grid[row][col] = player;
    return res;
}

bool isBoardFull(char grid[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] != 'x' && grid[i][j] != 'o')
                return false;
    return true;
}


int Minimax(char grid[3][3], int depth, bool isMaxi, char player, int alpha, int beta) {
    if (WinCondition(grid, 'o')) return 10;
    if (WinCondition(grid, 'x')) return -10;
    if (isBoardFull(grid) || depth == 0) return 0;

    if (isMaxi) {
        int bestScore = INT_MIN;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] != 'x' && grid[i][j] != 'o') {
                    char move = '1' + i * 3 + j;
                    S newGrid = doMove(grid, move, player);
                    char nplayer = changePlayer(player);
                    int score = Minimax(newGrid.grid, depth - 1, false, nplayer, alpha, beta);
                    bestScore = std::max(score, bestScore);
                    alpha = std::max(alpha, score);
                    if (beta <= alpha) break;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] != 'x' && grid[i][j] != 'o') {
                    char move = '1' + i * 3 + j;
                    S newGrid = doMove(grid, move, player);
                    char nplayer = changePlayer(player);
                    int score = Minimax(newGrid.grid, depth - 1, true, nplayer, alpha, beta);
                    bestScore = std::min(score, bestScore);
                    beta = std::min(beta, score);
                    if (beta <= alpha) break;
                }
            }
        }
        return bestScore;
    }
}




char comp(char grid[3][3]) {
    int bestScore = INT_MIN;
    char bestMove = '5';
    char player = 'o';
    S newGrid;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] != 'x' && grid[i][j] != 'o') {
                char move = '1' + i * 3 + j;
                newGrid = doMove(grid, move, player);
                if (WinCondition(newGrid.grid, 'o')) {
                    return move;
                }
                if (WinCondition(newGrid.grid, 'x')) {
                    return move;
                }
                int score = Minimax(newGrid.grid, 9, false, player, INT_MIN, INT_MAX);
                std::cout << "Evaluating move: " << move << ", Score: " << score << std::endl;

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = move;
                }
            }
        }
    }
    return bestMove;
}


/*

All func needed :

MiniMax // Main logic the best move
GeneratePossibleMove // return a panel of move
ExecMove // return a new grid
main // compile all func

*/