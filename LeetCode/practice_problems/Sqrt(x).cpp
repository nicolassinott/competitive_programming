class Solution {
public:
    int mySqrt(int x) {
        long long square;
        int left = 0;
        int right = x;
        int middle;

        while(left <= right){
            middle = (right - left)/2 + left;
            square = (long long) middle * middle;

            if(square == x){
                return middle;
            } else if(square > x){
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return right;
    }
};