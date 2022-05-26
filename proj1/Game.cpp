//
// Created by jiangfan on 22-5-21.
//

#include "Game.h"

bool Game::solve(){
    boards_to_visit.append(cur_board);
    while (boards_to_visit.num > 0){
        Board board = boards_to_visit.pop();
        boards_visited.append(board);
        /* EXIT. */
        if (board.is_solved()){
            cout<<"solved."<<endl;
            int solution[100];
            int k = 0;
            Board *ptr = &board;
            while (ptr->parent != NULL){
                //cout<<ptr->dir;
                solution[k++] = ptr->dir;
                ptr = ptr->parent;
            }
            for (int i = k - 1; i >= 0; i--) {
                cout << directions[solution[i]];
            }
            return true;
        }

        Board storage = board;
        for (int i = 0; i < 4; i++){
            board.move(i);
            if (!boards_visited.contains(board)){
                board.parent = &boards_visited.nodes[boards_visited.num - 1];
                boards_to_visit.append(board);
            }
            board = storage;
        }
        boards_to_visit.sort_by_cost();
        //boards_to_visit.output();
        //return false;
    }

    cout<<"no solution."<<endl;
    return false;
}

void Game::output(){
    cur_board.output();
    cout<<"----------------"<<endl;
}