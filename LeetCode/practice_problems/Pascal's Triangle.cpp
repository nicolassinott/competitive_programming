class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> retVec;
        vector<int> temp;

        for(int i = 0; i < numRows; i++){
            temp.push_back(1);
            
            for(int j = 1; j < i; j++){
                temp.push_back(retVec[i-1][j-1] + retVec[i-1][j]);
            }

            if(i > 0){
                temp.push_back(1);
            }

            retVec.push_back(temp);
            temp.clear();
        }

        return retVec;
    }
};