//
// Created by jiangfan on 22-5-21.
//

#include "Board.h"

/**
 * 计算输入i在棋盘上对应的坐标.
 * @param i
 * @return
 */
int* Board::map_rc(int i){
    int* a = new int[2];
    a[1] = (i - 1) % 3;
    a[0] = (i - a[1] - 1) / 3;
    return a;
}

/**
 * 计算所有节点距离终点的的预计代价之和.
 * 启发函数选取曼哈顿距离
 * @return
 */
int Board::calc_cost(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (data[i][j] != 0) {
                int row = map_rc(data[i][j])[0];
                int col = map_rc(data[i][j])[1];
                cost += abs(row - i) + abs(col - j);
            }
        }
    }
    return cost;
}
/**
 * 判断两个棋盘是否一样.
 * @param val
 * @return
 */
bool Board::equals(const Board& node){
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (data[i][j] != node.data[i][j])
                return false;
    return true;
}
/**
 * 判断是否求解结束.
 * @return
 */
bool Board::is_solved(){
    return equals(ans);
}

/**
 * 移动棋子.
 * @param dir
 */
void Board::move(int dir) {
    //right 0, down 1, left 2, up 3
    this->dir = dir;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (data[i][j] != 0) { continue; }
            switch (dir) {
                case 0:
                    if (j != 0) {
                        data[i][j] = data[i][j - 1];
                        data[i][j - 1] = 0;
                    }
                    break;
                case 1:
                    if (i != 0) {
                        data[i][j] = data[i - 1][j];
                        data[i - 1][j] = 0;
                    }
                    break;
                case 2:
                    if (j != 2) {
                        data[i][j] = data[i][j + 1];
                        data[i][j + 1] = 0;
                    }
                    break;
                case 3:
                    if (i != 2) {
                        data[i][j] = data[i + 1][j];
                        data[i + 1][j] = 0;
                    }
                    break;
            }
            cost = calc_cost();
            step += 1;
            return;
        }
    }
}

/**
 * 打印棋盘.
 */
void Board::output(){
    cout<<endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (data[i][j] == 0) {
                cout << "  ";
            } else {
                cout << data[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout<<"cost="<<cost<<endl;
    cout<<"step="<<step<<endl;
}