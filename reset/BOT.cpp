#include <climits>
#include <vector>



int minimax(std::vector<std::vector<char>> board, int deep, bool isMaxi, int alpha, int beta){

    return 0;
}



std::pair<int, int> findBestMove(std::vector<std::vector<char>> board) {
    int bestVal = INT_MIN;
    std::pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'x' && board[i][j] != 'o') {
                int cellValue = board[i][j];
                board[i][j] = 'o';
                int moveVal = minimax(board, 9, false, INT_MIN, INT_MAX);
                board[i][j] = cellValue;

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove
}