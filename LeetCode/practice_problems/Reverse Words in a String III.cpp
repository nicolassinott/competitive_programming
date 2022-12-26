class Solution {
public:
    string reverseWords(string s) {
        vector<vector<char>> words;
        vector<char> currWord;
        for(char i : s){
            if(i == ' '){
                if(!currWord.empty())
                    words.push_back(currWord);
                    currWord.clear(); 
            } else {
                currWord.push_back(i);
            }
        }

        words.push_back(currWord);

        string returnString = "";

        for(vector<char> v : words){
            for(int i = v.size() - 1; i >= 0; i--){
                returnString += v[i];
            }
            returnString += ' ';
        }

        return returnString.substr(0,returnString.size() - 1); 
    }
};