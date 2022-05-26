#include <iostream>
#include <gtest/gtest.h>
#include "Game.h"
using namespace std;

int main() {
    int case1[3][3] = {{1,2,3},{7,4,6},{0,5,8}};
    Board board1(case1);
    Game game1(board1);
    game1.output();
    game1.solve();

    int case2[3][3] = {{1,5,2},{4,3,0},{7,8,6}};
    Board board2(case2);
    Game game2(board2);
    game2.output();
    game2.solve();

    int case3[3][3] = {{5,3,4},{2,1,7},{8,0,6}};
    Board board3(case3);
    Game game3(board3);
    game3.output();
    game3.solve();

    int case4[3][3] = {{1,2,3},{4,5,6},{8,7,0}};
    Board board4(case4);
    Game game4(board4);
    game4.output();
    game4.solve();
    return 0;
}
