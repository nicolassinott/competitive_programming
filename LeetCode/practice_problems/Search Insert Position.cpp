class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;

        while(left <= right){
            middle = (right - left)/2 + left;
            if(nums.at(middle) == target){
                return middle;
            } else if(nums.at(middle) < target){
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return left;
    }
};