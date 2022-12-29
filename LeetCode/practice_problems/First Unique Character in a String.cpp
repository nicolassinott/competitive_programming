class Solution {
public:
    int firstUniqChar(string s) {

        char letters[26];
        for(int i = 0; i < 26; i++){
            letters[i] = 0;
        }

        int curr = 0;
        letters[s[curr] - 'a']++;

        for(int i = 1; i < s.size(); i++){

            if(curr == i && letters[s[i] - 'a']){
                curr++;
            } else if(curr != i && s[i] == s[curr]){
                curr++;
                while(curr < i && letters[s[curr] - 'a'] != 1){
                    curr++;
                }
                if(curr == i)
                    curr++;
            } 

            letters[s[i] - 'a']++;
        }

        return curr == s.size() ? -1 : curr;
    }
};