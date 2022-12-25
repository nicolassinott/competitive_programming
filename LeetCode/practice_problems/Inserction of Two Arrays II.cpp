#include <unordered_map>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> answer;

        for(int i = 0; i < nums1.size(); i++){
            if(mp.count(nums1[i])){
                mp[nums1[i]]++;
            } else{
                mp[nums1[i]] = 1;
            }
        }

        for(int i = 0; i < nums2.size(); i++){
            if(mp.count(nums2[i]) && mp[nums2[i]]){
                answer.push_back(nums2[i]);
                mp[nums2[i]] --;
            }
        }

        return answer;
    }
};