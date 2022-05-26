//
// Created by jiangfan on 22-5-21.
//

#ifndef UNTITLED_BOARDS_H
#define UNTITLED_BOARDS_H

# include "Board.h"

class Boards{
private:
    /* 存储棋盘 */
    Board nodes[1000];
    /* 棋盘实际大小 */
    int num;
public:
    Boards():num(0){}
    /* 添加结点 */
    void append(const Board& node);
    /* 弹出结点 */
    Board pop();
    /* 排序 */
    void sort_by_cost();
    /* 输出函数 */
    void output();
    /* 判断是否包含某棋盘 */
    bool contains(const Board& node);
    /* 友元 */
    friend class Game;
};

#endif //UNTITLED_BOARDS_H
