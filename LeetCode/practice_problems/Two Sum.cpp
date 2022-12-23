#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> retVector;

        int count = 0;

        for(int i : nums){
            if(mp.count(target - i)){
                retVector.push_back(mp[target - i]);
                retVector.push_back(count);
            } else {
                mp.insert({i,count});
            }
            count++;
        }
        return retVector;
    }
};