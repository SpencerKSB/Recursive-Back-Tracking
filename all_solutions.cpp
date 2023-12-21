#include <iostream>
#include <iomanip>

const int BOARD_SIZE = 3;
const int EMPTY_CELL = 0;

void printBoard(const int board[][BOARD_SIZE], const int& solutionsCounter);
bool validateMove(const int board[][BOARD_SIZE], const int& row, const int& col, const int& num);
bool solveSudoku(int board[][BOARD_SIZE], int& solutionsCounter);

void printBoard(const int board[][BOARD_SIZE], const int& solutionsCounter) {
    std::cout << std::setw(3) << "Solution #" << solutionsCounter << std::endl;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            std::cout << std::setw(2) << board[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "----------" << std::endl;
}

bool validateMove(const int board[][BOARD_SIZE], const int& row, const int& col, const int& num) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(int board[][BOARD_SIZE], int& solutionsCounter) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY_CELL) {
                for (int num = 1; num <= BOARD_SIZE; num++) {
                    if (validateMove(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board, solutionsCounter)) {
                            printBoard(board, solutionsCounter);
                        }
                        board[row][col] = EMPTY_CELL;
                    }
                }
                return false;
            }
        }
    }
    solutionsCounter++;
    return true;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
    };
    int solutionsCounter = 0;
    solveSudoku(board, solutionsCounter);
    return 0;
}
