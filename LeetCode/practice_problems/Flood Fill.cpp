class Solution {
public:
    bool isValid(int x, int y, int mX, int mY){
        return (x>=0 && y>=0 && x<mX && y<mY) ? 1 : 0;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc])
            return image;

        stack<pair<int,int>> toVisit;
        vector<pair<int,int>> possible;
        int oldColor = image[sr][sc];

        toVisit.push({sr,sc});

        while(!toVisit.empty()){
            pair<int,int> curr = toVisit.top();
            toVisit.pop();

            image[curr.first][curr.second] = color;

            possible = {{curr.first-1, curr.second}, 
                        {curr.first+1, curr.second}, 
                        {curr.first, curr.second-1}, 
                        {curr.first,curr.second+1}};

            for(pair<int,int> possibleNode : possible){
                if(
                    isValid(possibleNode.first, possibleNode.second, image.size(), image[0].size()) && 
                    image[possibleNode.first][possibleNode.second] == oldColor 
                    )
                    toVisit.push({possibleNode.first, possibleNode.second});
            }
        }

        return image;
        
    }
};