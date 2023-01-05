class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int mX = mat.size();
        int mY = mat[0].size();
        int currX; int currY;
        queue<pair<int,int>> pqueue;

        for(int i = 0; i < mX; i++){
            for(int j = 0; j < mY; j++){
                if(!mat[i][j])
                    pqueue.emplace(i,j);
                else
                    mat[i][j] = -1;
            }
        }

        while(!pqueue.empty()){
            auto [x,y] = pqueue.front();
            pqueue.pop();
            
            for(int i = 0; i < 4; i++){
                currX = x+DIR[i]; currY = y + DIR[i+1];
                if(currX >= mX || currX < 0 || currY >= mY || currY < 0 || mat[currX][currY] != -1)
                    continue;
                mat[currX][currY] = mat[x][y] + 1;
                pqueue.emplace(currX,currY);
            }
        }

        return mat;
        
    }
};