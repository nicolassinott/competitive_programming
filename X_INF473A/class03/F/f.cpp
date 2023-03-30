#include <bits/stdc++.h>
using namespace std;

void update_chess_board(int& x, int& y, int& x_queen, int& y_queen, vector<vector<int>>& chess_board, int& free_spaces){
    for(int i = 0; i < y; i++){
        if(chess_board[x_queen][i] == 0){
            chess_board[x_queen][i] = 1;
            free_spaces--;
        }
    }

    for(int i = 0; i < x; i++){
        if(chess_board[i][y_queen] == 0){
            chess_board[i][y_queen] = 1;
            free_spaces--;
        }
    }

    int sum_xy = x_queen + y_queen;
    int sub_xy = x_queen - y_queen;

    int x_diag_up = x_queen; int x_diag_down = y_queen; 
    int y_diag_up = y_queen; int y_diag_down = y_queen;

    int min_diag_down = min(x_diag_down, y_diag_down);
    x_diag_down -= min_diag_down;
    y_diag_down -= min_diag_down;

    //do diagonals
}

int main(){
    int x, y, n_queens;
    cin >> x >> y >> n_queens;

    while(1){

        vector<vector<int>> chess_board(x, vector<int>(y, 0));
        int free_spaces = x * y;
        int x_queen, y_queen;
        
        for(int i = 0; i < n_queens; i++){
            cin >> x_queen >> y_queen;
            update_chess_board(x, y, x_queen, y_queen, chess_board, free_spaces);
        }
        
        cout << free_spaces << endl;
        
        cin >> x >> y >> n_queens;
        if(!x & !y & !n_queens) break;
    }

    return 0;
}
