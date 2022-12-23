class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum, maxSum;
        sum = 0;
        maxSum = INT_MIN;

        for(int i : nums){
            sum = max(i, sum + i);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};