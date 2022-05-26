//
// Created by jiangfan on 22-5-21.
//

#include "Boards.h"
/**
 * 将当前棋盘加入已遍历集合.
 * @param board
 */
void Boards::append(const Board& board){
    nodes[num++] = board;
}
/**
 * 根据估价函数的值进行优先级排序.
 */
void Boards::sort_by_cost() {
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (nodes[i].cost + nodes[i].step
                > nodes[j].cost + nodes[j].step) {
                Board tmp;
                tmp = nodes[j];
                nodes[j] = nodes[i];
                nodes[i] = tmp;
            }
        }
    }
}

/**
 * 输出棋盘集合.
 */
void Boards::output(){
    for (int i = 0; i < num; i++)
        nodes[i].output();
}

/**
 * 判断已遍历棋盘集中是否包含棋盘board.
 * @param board
 * @return
 */
bool Boards::contains(const Board& board){
    for (int i = 0; i < num; i++) {
        if (nodes[i].equals(board)) {
            return true;
        }
    }
    return false;
}

/**
 * 弹出已遍历集中最早遍历的棋盘.
 * @return
 */
Board Boards::pop() {
    Board temp = nodes[0];
    for (int i = 0; i < num - 1; i++) {
        nodes[i] = nodes[i + 1];
    }
    num--;
    return temp;
}
