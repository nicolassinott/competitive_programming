#include <bits/stdc++.h>
using namespace std;

void swap_row(vector<int>& M, vector<int> M_inv, int x, int y){
    int temp;

    if(x == y) return;

    for(int i = 0; i < 1234; i++){
        temp = M[i*5678 + x];

        M[i*5678 + x] = M[i*5678 + y];
        M[i*5678 + y] = temp;

        M_inv[M[i*5678 + x]] = i*5678 + x;
        M_inv[M[i*5678 + y]] = i*5678 + y;
    }

    return;
}

void swap_column(vector<int>& M, vector<int> M_inv, int x, int y){
    int temp;

    if(x == y) return;

    for(int i = 0; i < 1234; i++){
        temp = M[x*5678 + i];

        M[x*5678 + i] = M[y*5678 + i];
        M[y*5678 + i] = temp;

        M_inv[M[x*5678 + i]] = x*5678 + i;
        M_inv[M[y*5678 + i]] = y*5678 + i;
    }
    
    return;
}

void write_out(vector<int>& M, vector<int> M_inv, int x, int y){
    cout << M[x*5678 + y] << endl;
    return;
}

void write_out_inv(vector<int>& M, vector<int> M_inv, int x, int y){
    int pos = M_inv[x*5678 + y];
    int x_cor = pos /5678; 

    cout << x_cor << ' ' << pos - x_cor << endl; 

    return;
}

int main(){
    vector<int> M(1234*5678);
    vector<int> M_inv(1234*5678);
    int maximal_int = INT_MAX;
    char operation; int term1; int term2; int temp;
    int to_print;


    for(int i = 0; i < 1234*5678; i++){
        M[i] = i;
    }

    while(maximal_int--){
        cin >> operation;
        if(operation != 'W'){

        } else {

        }



        cin >> to_print;
        if(to_print != 42) cout << to_print << endl;
        else break;
    }

    

    return 0;

}