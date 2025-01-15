#include <vector>

#ifndef FUNC_H
#define FUNC_H


bool isWin(const std::vector<std::vector<char>>& board, char player);
bool isBoardFull(const std::vector<std::vector<char>>& board);
std::pair<int, int> findBestMove(std::vector<std::vector<char>>& board);
void printBoard(const std::vector<std::vector<char>>& board);
#endif
