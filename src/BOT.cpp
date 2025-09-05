#include <climits>
#include <vector>
#include <iostream>
#include "function.h"


int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaxi, int alpha, int beta){
  //    std::cout << "Evaluating move: " << std::endl;
  //  printBoard(board);
	    

  
    if (isWin(board, 'o')) return 10-(9-depth);
    if (isWin(board, 'x')) return -10-(9-depth);
    if (isBoardFull(board) || depth == 0) return 0;

    if (isMaxi) {
        int bestScore = INT_MIN;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 'x' && board[i][j] != 'o') {
                    int cellValue = board[i][j];
                    board[i][j] = 'o';
                    bestScore = std::max(bestScore, minimax(board, depth -1, !isMaxi, alpha, beta));
                    board[i][j] = cellValue;

                    alpha = std::max(alpha, bestScore);
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 'x' && board[i][j] != 'o') {
                    int cellValue = board[i][j];
                    board[i][j] = 'x';
                    bestScore = std::min(bestScore, minimax(board, depth -1, !isMaxi, alpha, beta));
                    board[i][j] = cellValue;

                    beta = std::min(beta, bestScore);
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return bestScore;
    }
}

std::pair<int, int> findBestMove(std::vector<std::vector<char>>& board) {
    int bestVal = INT_MIN;
    std::pair<int, int> bestMove = {1, 1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'x' && board[i][j] != 'o') {
                int cellValue = board[i][j];
                board[i][j] = 'o';
                int moveVal = minimax(board, 9, false, INT_MIN, INT_MAX);
		
		//	std::cout << ", Score: " << moveVal << std::endl;
		
                board[i][j] = cellValue;

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}
