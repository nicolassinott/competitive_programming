class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int begin = 0;
        int end = nums.size();

        int nZeros = 0;
        int left = 0;
        int temp;

        while(left < nums.size()){

            if(!nums[left]){
                nZeros++;
            } else{
                nums[left - nZeros] = nums[left];
            }
            left++;
        }

        while(nZeros--){
            nums[nums.size() - nZeros - 1] = 0;
        }

    }
};