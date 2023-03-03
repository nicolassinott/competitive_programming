class Solution {
public:
    int findFirst(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int middle;

        while(left <= right){
            middle = (right - left) / 2 + left;
            if(nums[middle] >= nums[0]) left = middle + 1;
            if(nums[middle] < nums[0]) right = middle - 1;
        }

        return left;
    }
    
    int search(vector<int>& nums, int target) {
        int smallest_index = findFirst(nums, target); ;

        int left = 0; 
        int right = nums.size() - 1;
        int middle;

        while(left <= right){
            middle = ((right - left)/2 + left + smallest_index) % nums.size();
            if (nums[middle] == target) return middle;
            else if (nums[middle] > target) right = right - 1;
            else left = left + 1; 
        }   

        return -1;
    }
};