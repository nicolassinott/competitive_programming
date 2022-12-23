#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> seen;

        for(int i : nums){
            if(seen.count(i)){
                return true;
            }
            seen.insert(i);
        }

        return false;
    }
};