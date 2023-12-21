#include <iostream>
#include <iomanip>

const int BOARD_SIZE = 3;
const int EMPTY_CELL = 0;

void printBoard(const int board[][BOARD_SIZE]);
bool validateMove(const int board[][BOARD_SIZE], const int& row, const int& col, const int& num);
bool solveSudoku(int board[][BOARD_SIZE]);

void printBoard(const int board[][BOARD_SIZE]) {
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

bool solveSudoku(int board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY_CELL) {
                for (int num = 1; num <= BOARD_SIZE; num++) {
                    if (validateMove(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = EMPTY_CELL;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int board1[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY_CELL, 2, EMPTY_CELL},
        {3, 1, EMPTY_CELL},
        {EMPTY_CELL, 3, EMPTY_CELL}
    };
    int board2[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {1, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, 3, EMPTY_CELL}
    };

    if (solveSudoku(board1)) {
        std::cout << "Board #1:" << std::endl;
        printBoard(board1);
    }
    if (solveSudoku(board2)) {
        std::cout << "Board #2:" << std::endl;
        printBoard(board2);
    }

    return 0;
}
