class Solution {
public:

    int findMiddle(vector<int>& nums, int target){
        int left = 0; int right = nums.size() - 1; int middle;
        while(left <= right){
            middle = (right - left) / 2 + left;
            if(nums[middle] == target) break;
            if(nums[middle] < target) left = middle + 1;
            else right = middle - 1;
        }
        return middle;
    }

    int findRight(vector<int>& nums, int target, int middleTarget){
        int left = middleTarget; int right = nums.size() - 1; int middle;
        while(left <= right){
            middle = (right - left) / 2 + left;
            if(nums[middle] == target) left = middle + 1;
            else right = middle - 1;
        } 
        return right;
    }

    int findLeft(vector<int>& nums, int target, int middleTarget){
        int left = 0; int right = middleTarget; int middle;
        while(left <= right){
            middle = (right - left) / 2 + left;
            if(nums[middle] == target) right = middle - 1; 
            else left = middle + 1;
        } 
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) 
            return {-1,-1};
        
        int left = 0; int right = nums.size()-1; 
        
        int middleTarget = findMiddle(nums, target);
        
        if(nums[middleTarget] != target) return {-1,-1};
        
        return {findLeft(nums, target, middleTarget), findRight(nums, target, middleTarget)};
    }
};