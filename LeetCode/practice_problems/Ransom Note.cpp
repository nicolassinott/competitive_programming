class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int magLetters[26] = {0};

        for (char ch : magazine)
            magLetters[ch - 'a']++;

        for (char ch : ransomNote)
            magLetters[ch - 'a']--;

        for(int i : magLetters){
            if(i < 0)
                return 0;
        }

        return 1;
    }
};