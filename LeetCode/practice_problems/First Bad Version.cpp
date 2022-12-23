// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        int middle;

        while(left <= right){
            middle = (right - left) / 2 + left;
            if(isBadVersion(middle)){
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return left;
    }
};