class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left, right, curr;
        left = 0;
        right = numbers.size() - 1;

        while(left < right){
            curr = numbers[left] + numbers[right];
            if(curr == target){
                return vector<int>({left + 1, right + 1});
            } else {
                if(curr < target){
                    left++;
                } else {
                    right--;
                }
            }
        }

        return numbers;
    }
};