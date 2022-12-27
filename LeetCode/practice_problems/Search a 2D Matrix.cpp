class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        int middle;

        int x,y;

        while(left <= right){
            middle = (right - left) / 2 + left;
            x = middle / n;
            y = middle - x*n;
            
            if(matrix[x][y] == target)
                return 1;
            else if (matrix[x][y] > target)
                right = middle - 1;
            else 
                left = middle + 1;
        }

        return 0;
    }
};