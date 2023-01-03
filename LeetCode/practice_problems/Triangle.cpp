class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> minSum = {{triangle[0][0]}};
        vector<int> temp;

        for(int i = 1; i < triangle.size(); i++){
            temp.push_back({triangle[i][0] + minSum[i-1][0]});
            
            for(int j = 1; j < i; j++){
                temp.push_back(triangle[i][j] + min(minSum[i-1][j], minSum[i-1][j-1]));
            }

            temp.push_back(triangle[i][i] + minSum[i-1][i-1]);
            minSum.push_back(temp);
            temp.clear();
        }

        int minEl = minSum[minSum.size()-1][0];  

        for(int el : minSum[minSum.size() - 1]){
            if (el < minEl)
                minEl = el;
        }

        return minEl;
    }
};