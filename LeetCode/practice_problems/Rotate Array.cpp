class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> answer(l);

        k = k % l;

        for(int i = 0; i < l; i++){
            cout << (l-k+i)%l;
            answer.at(i) = nums.at((l-k+i)%l);
        }

        nums = answer; 
    }
};