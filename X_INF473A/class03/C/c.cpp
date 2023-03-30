#include <bits/stdc++.h>
using namespace std;

int get_weight(vector<int>& fruits, int i, int j){
    // Includes fruits i and j
    return fruits[j] - fruits[i-1];
}

void backtracking(vector<int>& fruits, vector<int>& current_basket, int& total_weight){
    
    
    return;
}

int main(){
    int n; cin >> n;
    
    vector<int> fruits(n);
    cin >> fruits[0];
    for(int i = 1; i < n; i++){
        cin >> fruits[i];
        fruits[i] += fruits[i-1];
    }
    
    for(int i = 0; i < n; i++){
        int weight = 0;


    }






    return 0;
}
