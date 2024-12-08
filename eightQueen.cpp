#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

// 定义最大棋盘规模，可根据实际需求调整，也可以考虑改为动态分配内存的方式来更灵活地适配不同大小棋盘
const int MAX_BOARD_SIZE = 50;  

// 模拟棋盘，用于记录皇后的放置位置，a[i][j] = 1表示在第i行第j列放置了皇后，否则为0
int chessBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE];  
// 用于记录每一列是否已经放置了皇后，columnOccupied[j] = 1表示第j列已有皇后，为0则表示该列还未放置皇后
int columnOccupied[MAX_BOARD_SIZE];  
// 用于记录从左上角到右下角的斜线上是否已有皇后，通过特定的坐标变换来标记不同斜线上的占用情况
// diagonalPlusOccupied[i] = 1表示对应斜线已被皇后占据，为0表示可放置皇后
int diagonalPlusOccupied[MAX_BOARD_SIZE * 2];  
// 用于记录从右上角到左下角的斜线上是否已有皇后，同样通过坐标变换来标记占用情况
// diagonalMinusOccupied[i] = 1表示对应斜线已被皇后占据，为0表示可放置皇后
int diagonalMinusOccupied[MAX_BOARD_SIZE * 2];  

// 棋盘的规模，即n * n的棋盘，通过用户输入获取其值
int boardSize;  
// 用于统计找到的满足皇后放置条件的解的个数
int solutionCount = 0;  

// 函数功能：在棋盘的指定位置 (row, col) 放置皇后，并相应地更新记录皇后放置情况的各个标记数组
// 参数说明：
// - row：表示要放置皇后的行索引，从0开始计数
// - col：表示要放置皇后的列索引，从0开始计数
void placeQueen(int row, int col) {
    chessBoard[row][col] = 1;  // 在棋盘对应位置标记放置了皇后
    columnOccupied[col] = 1;  // 标记该列已被皇后占据
    diagonalPlusOccupied[row + col] = 1;  // 标记从左上角到右下角的对应斜线已被占据
    diagonalMinusOccupied[row - col + boardSize] = 1;  // 标记从右上角到左下角的对应斜线已被占据
}

// 函数功能：移除棋盘指定位置 (row, col) 上的皇后，并相应地更新记录皇后放置情况的各个标记数组
// 参数说明：
// - row：表示要移除皇后的行索引，从0开始计数
// - col：表示要移除皇后的列索引，从0开始计数
void removeQueen(int row, int col) {
    chessBoard[row][col] = 0;  // 在棋盘对应位置清除皇后标记
    columnOccupied[col] = 0;  // 标记该列不再有皇后占据
    diagonalPlusOccupied[row + col] = 0;  // 清除从左上角到右下角对应斜线的皇后占据标记
    diagonalMinusOccupied[row - col + boardSize] = 0;  // 清除从右上角到左下角对应斜线的皇后占据标记
}

// 函数功能：判断在棋盘的指定位置 (row, col) 是否可以放置皇后
// 参数说明：
// - row：表示要判断的行索引，从0开始计数
// - col：表示要判断的列索引，从0开始计数
// 返回值：如果该位置已经有皇后（通过检查各个标记数组对应位置的值判断）则返回true，表示不能放置皇后；
//         如果该位置没有皇后，即所有相关标记数组对应位置的值都为0，则返回false，表示可以放置皇后
bool isPositionAvailable(int row, int col) {
    return chessBoard[row][col] == 1 ||
           columnOccupied[col] == 1 ||
           diagonalPlusOccupied[row + col] == 1 ||
           diagonalMinusOccupied[row - col + boardSize] == 1;
}

// 函数功能：输出当前找到的满足皇后放置条件的解，最多输出九组解
// 实现逻辑：当找到的解的数量小于9时，遍历整个棋盘，对于每一行，如果在某列放置了皇后（即chessBoard[i][j] == 1），
//           则输出该列的索引（从1开始，所以输出 j + 1），然后换行表示一行输出完毕。每输出一组解后，solutionCount自增1。
void outputSolution() {
    if (solutionCount < 9) {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (chessBoard[i][j] == 1) {
                    cout << j + 1 << " ";
                }
            }
        }
        cout << endl;
    }
    solutionCount++;
}

// 函数功能：使用深度优先搜索算法来尝试在棋盘上放置皇后，以找到满足条件的解
// 参数说明：
// - currentRow：表示当前正在处理的行索引，从0开始计数，递归调用时会不断更新，用于逐行放置皇后
void depthFirstSearch(int currentRow) {
    if (currentRow == boardSize) {  // 如果已经处理完所有行（即成功放置完所有皇后）
        outputSolution();  // 输出当前找到的解
    }
    else {
        for (int col = 0; col < boardSize; col++) {  // 遍历当前行的每一列
            if (!isPositionAvailable(currentRow, col)) {  // 如果当前位置可以放置皇后（即该位置没有被其他皇后攻击）
                placeQueen(currentRow, col);  // 在该位置放置皇后
                depthFirstSearch(currentRow + 1);  // 递归处理下一行，继续放置皇后
                removeQueen(currentRow, col);  // 在递归返回后（可能是下一行放置皇后失败或者已经完成一种放置方案的探索），移除当前位置的皇后，以便尝试其他列位置放置皇后
            }
        }
    }
}

int main() {
    cin >> boardSize;  // 获取用户输入的棋盘规模
    depthFirstSearch(0);  // 从棋盘的第一行（索引为0）开始进行深度优先搜索，尝试放置皇后并寻找解
    cout << solutionCount << endl;  // 输出找到的解的总数
    return 0;
}