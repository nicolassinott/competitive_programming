#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_valid(int x, int y, int& n, int& m){
    return !(x < 0 || x >= n || y < 0 || y >= m);
}

vector<pair<int,int>> next_iterations(int x, int y, int&n, int&m, int k){
    vector<pair<int,int>> next_it;
    if(is_valid(x+k,y,n,m)) next_it.push_back({x+k,y});
    if(is_valid(x-k,y,n,m)) next_it.push_back({x-k,y});
    if(is_valid(x,y+k,n,m)) next_it.push_back({x,y+k});
    if(is_valid(x,y-k,n,m)) next_it.push_back({x,y-k});
    return next_it;    
}

int main() {
    int n, m; cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<bool>> seen(n, vector<bool>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch; cin >> ch;
            matrix[i][j] = ch -'0';
        }
    }

    queue<vector<int>> bfs; bfs.push({0,0,0});
    seen[0][0] = 1;

    bool found = 0;
    int n_steps;

    while(!bfs.empty()){
        vector<int> curr = bfs.front(); bfs.pop();
        int x,y,steps,k;
        x = curr[0]; y = curr[1]; steps = curr[2];
        k = matrix[x][y];

        if(x == n-1 && y == m-1) {
            found = 1;
            n_steps = steps;
            break;
        }

        vector<pair<int,int>> next_it = next_iterations(x,y,n,m,k);

        for(auto[x,y] : next_it){
            if(!seen[x][y]){
                bfs.push({x,y,steps+1});
                seen[x][y] = 1;
            }
        }
    }

    if(!found) cout << -1 << endl;
    else cout << n_steps << endl;

    return 0;
}