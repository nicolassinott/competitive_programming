#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    
    int total_size = coins[coins.size()-1] + coins[coins.size()-2] + 1;
    vector<int> possible_sums(total_size,total_size);
    possible_sums[0] = 0;

    for(int i = n-1; i >=0; i--){
        int coin = coins[i];
        for(int j = 0; j < total_size-coin; j++)
            if(possible_sums[j] != total_size) 
                possible_sums[j + coin] = min(possible_sums[j+coin], possible_sums[j]+1);
    }

    bool non_canonical = 0;

    for(int value = total_size-1; value >=1; value--){        
        int greedy = 0;

        int coin_index = n-1;
        int dummy_value = value;
        while(dummy_value!=0){
            if(dummy_value < coins[coin_index]) coin_index--;
            int dummy = (int) dummy_value / coins[coin_index];

            dummy_value -= dummy * coins[coin_index]; 
            greedy += dummy;
        }

        if(greedy > possible_sums[value]) {
            non_canonical = 1;
            break;
        }
    }

    if(!non_canonical) cout << "canonical" << endl;
    else cout << "non-canonical" << endl; 

    return 0;
}