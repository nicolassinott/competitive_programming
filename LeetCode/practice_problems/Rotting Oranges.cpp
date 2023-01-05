class Solution {
public:
    vector<int>DIR = {0,1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        queue<pair<int,int>> pqueue;
        int nx; int ny;
        int maxDay = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) grid[i][j] = -2;
                else if(grid[i][j] == 1) grid[i][j] = -1;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    grid[i][j] = 0;
                    pqueue.emplace(i,j);
                } 
            }
        }

        while(!pqueue.empty()){
            auto [x,y] = pqueue.front(); pqueue.pop();
            for(int i = 0; i < 4; i++){
                nx = x + DIR[i]; ny = y + DIR[i+1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != -1) continue;
                grid[nx][ny] = grid[x][y] + 1;
                pqueue.emplace(nx,ny);
            }
        }

        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == -1) return -1;
                if(grid[i][j] > maxDay) maxDay = grid[i][j];
            }
        }

        return maxDay;

    }
};