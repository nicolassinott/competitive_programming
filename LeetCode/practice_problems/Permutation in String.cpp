class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int strSize = s1.size();
        unordered_map<char, int> mp;
        int start = 0;

        for(char ch : s1){
            if(!mp.count(ch))
                mp[ch] = 1;
            else 
                mp[ch]++;
        }

        for(int i = 0; i < s2.size(); i++){
            cout << i << ' ' << strSize << endl;
            if(mp.count(s2[i])){
                if(mp[s2[i]] == 0){
                    while(s2[start] != s2[i]){
                        mp[s2[start]]++;
                        start++;
                        strSize++;
                    }
                    start++;
                } else {
                    mp[s2[i]]--;
                    strSize--;
                }
            } else {
                while(start < i){
                    mp[s2[start]]++;
                    strSize++;
                    start++;
                }
                start++;
            }
            
            if(!strSize){
                return true;
            }
        }

        return false;
    }
};