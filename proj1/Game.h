//
// Created by jiangfan on 22-5-21.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

# include "Boards.h"
# include <string>
class Game{
private:
    Board cur_board;
    Boards boards_visited;
    Boards boards_to_visit;
    string directions[4] = {"Right ", "Down ", "Left ", "Up "};
public:
    Game(Board board):cur_board(board){};
    bool solve();
    void output();
};

#endif //UNTITLED_GAME_H
