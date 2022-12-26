class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        int middle;
        long long middleSquare;

        while(left <= right){
            middle = (right - left) / 2 + left;

            middleSquare = (long) middle * middle;

            if (middleSquare == num){
                return 1;
            } else if (middleSquare < num) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return 0;
    }
};