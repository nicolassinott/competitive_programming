class Solution {
public:
    
    bool isValid(int x, int y, int mX, int mY){
        return (x>=0 && y>=0 && x<mX && y<mY) ? 1 : 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        stack<pair<int,int>> toVisit;
        int currArea = 0;
        int maxArea = 0;
        vector<pair<int,int>> neigh;
        int currX, currY, neighX, neighY;

        for(int x = 0; x < grid.size(); x++){
            for(int y = 0; y < grid[0].size(); y++){
                if(!grid[x][y]) continue;
                
                toVisit.push({x,y});
                grid[x][y] = 0;
                while(!toVisit.empty()){
                    pair<int,int> curr = toVisit.top(); 
                    toVisit.pop();
                    currX = curr.first; 
                    currY = curr.second;
                    currArea++;

                    neigh = {{currX-1,currY}, {currX+1,currY}, {currX,currY-1}, {currX,currY+1}};

                    for(pair<int,int> neighNode : neigh){
                        neighX = neighNode.first;
                        neighY = neighNode.second;
                        if(
                            isValid(neighX, neighY, grid.size(), grid[0].size()) &&
                            grid[neighX][neighY]
                            ){
                                toVisit.push({neighX,neighY});
                                grid[neighX][neighY] = 0;
                            }   
                    }

                }
                maxArea = max(currArea, maxArea);
                currArea = 0;
            }
        }

        return maxArea;

    }
};