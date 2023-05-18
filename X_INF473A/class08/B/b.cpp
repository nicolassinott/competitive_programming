#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        string str; cin >> str;
        bitset<23> state;
        vector<int> seen(1e7);
        stack<pair<bitset<23>,int>> states;

        for(int i = 0; i < 23; i++) state[i] = str[i] == 'o';

        int minimum_ones = state.count();
        states.push({state, minimum_ones});
        
        while(!states.empty()){
            auto par = states.top();
            state = par.first; int curr_ones = par.second;
            states.pop();

            minimum_ones = min(minimum_ones, curr_ones);

            // updates the state minimum state of 1s
            int state_value = state.to_ulong(); 
            seen[state_value] = 1;

            // generate new possible states                       
            for(int i = 0; i < 21; i++){
                int left = i; int middle = i+1; int right = i+2;
                bitset<23> new_state;
                
                if(!state[left] && state[middle] && state[right]){
                    new_state = state;
                    new_state[left] = 1; new_state[middle] = 0; new_state[right] = 0;
                    if(!seen[new_state.to_ulong()]) states.push({new_state, curr_ones-1});
                }

                if(state[left] && state[middle] && !state[right]){
                    new_state = state;
                    new_state[left] = 0; new_state[middle] = 0; new_state[right] = 1;
                    if(!seen[new_state.to_ulong()]) states.push({new_state, curr_ones-1});
                }
            }
        }
        cout << minimum_ones << endl;
    }

    return 0;
}