class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size() == 0){
            return 0;
        }

        if(nums.size() == 1){
            return nums.at(0) == target  ? 0 : -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        
        while(right >= left){
            int middle = (right - left) / 2 + left;
            if(nums.at(middle) == target){
                return middle;
            } else if(nums.at(middle) < target){
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return -1;
    }
};