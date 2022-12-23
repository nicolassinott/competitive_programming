class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer(nums.size());
        int start = 0;
        int end = nums.size() - 1;

        for(int i = nums.size() - 1; i >= 0; i--){
            if(abs(nums.at(start)) > abs(nums.at(end))){
                answer.at(i) = pow(nums.at(start),2);
                start++;
            } else {
                answer.at(i) = pow(nums.at(end),2);
                end--;
            }
        }

        return answer;
    }
};