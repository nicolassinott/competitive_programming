
class Solution {
public:
    bool isValid(int x, int y, int mX, int mY){
        return x>=0 && y>=0 && x<mX && y<mY;
    }

    vector<pair<int,int>> neighbors(int x, int y, int mX, int mY){
        vector<pair<int,int>> answer;
        if(isValid(x+1,y,mX,mY)) answer.push_back({x+1,y});
        if(isValid(x-1,y,mX,mY)) answer.push_back({x-1,y}); 
        if(isValid(x,y+1,mX,mY)) answer.push_back({x,y+1});
        if(isValid(x,y-1,mX,mY)) answer.push_back({x,y-1});
        return answer;  
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> answer;
        int currMin;
        int remainingNeigh;
        int nextRemainingNeigh;
        queue<pair<int,int>> bfsQueue;
        pair<int,int> currPair;
        set<pair<int,int>> visited;
        int mX = mat.size();
        int mY = mat[0].size();
        vector<int> temp;

        for(int i = 0; i < mX; i++){
            for(int j = 0; j < mY; j++){
                currMin = 0;
                if(!mat[i][j]){
                    temp.push_back(currMin);
                    continue;
                } 
                
                bfsQueue.push({i,j});
                remainingNeigh = 1;
                nextRemainingNeigh = 0;
                while(!bfsQueue.empty()){
                    currPair = bfsQueue.front();
                    bfsQueue.pop();
                    if(!remainingNeigh){
                        remainingNeigh = nextRemainingNeigh;
                        nextRemainingNeigh = 0;
                        currMin++;
                    }
                    if(!mat[currPair.first][currPair.second]) break;
                    visited.insert(currPair);
                    for(pair<int,int> neigh : neighbors(currPair.first, currPair.second, mX, mY)){
                        if(!visited.count(neigh)) {
                            bfsQueue.push(neigh);
                            nextRemainingNeigh++;
                        }
                    }
                    remainingNeigh--;
                }
                
                while(!bfsQueue.empty())
                    bfsQueue.pop();
                visited.clear();
                temp.push_back(currMin);
            }
            answer.push_back(temp);
            temp.clear();
        }

        return answer;
    }
};