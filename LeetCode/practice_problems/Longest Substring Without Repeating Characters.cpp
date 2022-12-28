class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        
        int maxLen = 0;
        int currLen = 0;

        int bString = 0;

        for(int i = 0; i < s.size(); i++){
            if(mp.count(s[i])){
                while(s[bString] != s[i]){
                    mp.erase(s[bString]);
                    bString++;
                    currLen--;
                }
                bString++;
            } else {
                mp.insert(s[i]);
                currLen++;
            } 
            
            maxLen = max(maxLen,currLen);
        }
        return maxLen;
    }
};