#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int max_weight;
    int n;

    while(cin >> max_weight >> n){
        
        vector<int> weights(n + 1);
        vector<int> prices(n + 1);

        vector<vector<pair<ll,ll>>> solution(n+1, vector<pair<ll,ll>>(max_weight+1));

        for(int w = 0; w <= max_weight; w++){
            solution[0][w].first = 0;
        }

        for(int i = 1; i <= n; i++){
            cin >> prices[i] >> weights[i];
        }

        for(int i = 1; i <= n; i++){
            for(int w = 0; w <= max_weight; w++){
                if(weights[i] <= w){
                    if(prices[i] + solution[i-1][w - weights[i]].first > solution[i-1][w].first){
                        solution[i][w] = {prices[i] + solution[i-1][w - weights[i]].first, i};
                    }
                    else {
                        solution[i][w] = {solution[i-1][w].first, -1};
                    }
                }
                else {
                    solution[i][w] = {solution[i-1][w].first,-1};
                }
            }
        }
        
        vector<int> taken;

        for(int i = n; i > 0; i--){
            if(~solution[i][max_weight].second){
                taken.push_back(solution[i][max_weight].second - 1);
                max_weight -= weights[solution[i][max_weight].second];
            }
        }

        cout << taken.size() << endl;
        for(int& el : taken){
            cout << el << ' ';
        }
        cout << endl;

    }    

    return 0;
}