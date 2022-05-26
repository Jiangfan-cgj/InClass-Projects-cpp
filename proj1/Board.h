//
// Created by jiangfan on 22-5-21.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

# include <iostream>
using namespace std;

class Board {
private:
    int data[3][3];
    /* 方向 */
    int dir;
    Board* parent;
    /**/
    int ans[3][3] = {{1,2,3}, {4,5,6},{7,8,0}};
    /* 实际代价 */
    int step;
    /* 预计代价 */
    int cost;
public:
    Board(){}
    Board(const int a[3][3]){
        step = cost = 0;
        parent = NULL;
        copy(&a[0][0], &a[0][0] + 3*3,&data[0][0]);
        cost = calc_cost();
    }

    /* 每个棋子的最终位置*/
    int* map_rc(int);
    /* 计算代价 */
    int calc_cost();
    /* 判断两个棋盘是否相等 */
    bool equals(const Board&);
    /* 判断是否解决 */
    bool is_solved();
    /* 移动棋盘 */
    void move(int);
    /* 打印棋盘 */
    void output();
    /* 友元 */
    friend class Boards;
    friend class Game;
};

#endif //UNTITLED_BOARD_H
