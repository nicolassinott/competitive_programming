class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n != r*c)
            return mat;

        vector<vector<int>> retMat;
        vector<int> temp;
        int curr = 0;

        for(int nX = 0; nX < r; nX++){
            
            for(int nY = 0; nY < c; nY++){
                int oX = curr/n;
                int oY = curr - oX * n;
                temp.push_back(mat[oX][oY]); 
                curr++;
            }

            retMat.push_back(temp);
            temp.clear();
        }

        return retMat;
    }
};