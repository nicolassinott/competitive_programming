class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return 0;
        
        int letters[26] = {0};

        for(char ch : s)
            letters[ch - 'a']++;     

        for(char ch : t)
            letters[ch - 'a']--;
        

        for(int i : letters){
            if (i != 0)
                return 0;
        }

        return 1;
    }
};