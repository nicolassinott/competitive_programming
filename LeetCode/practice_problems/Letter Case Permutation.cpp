class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> answer = {""};
        vector<string>* ptrAnswer = &answer;
        vector<string> aux;
        vector<string>* ptrAux = &aux;
        vector<string>* ptrExtra;

        int currSize = 1;
        int tempCurrSize;

        string currWord;

        for(char ch : s){
            cout << "yay" << endl;
            tempCurrSize = currSize;
            if(isdigit(ch)){
                cout << "yay2" << endl;
                for(int i = 0; i < currSize; i++){
                    // does not work answer[i] += ch;
                    ptrAnswer->at(i) += ch;
                }
            } else {
                
                for(int i = 0; i < currSize; i++){
                    currWord = ptrAnswer->back();
                    ptrAnswer->pop_back();
                    ptrAux->push_back(currWord + (char)tolower(ch));
                    ptrAux->push_back(currWord + (char)toupper(ch));
                    tempCurrSize++;
                }
                currSize = tempCurrSize;
                ptrExtra = ptrAnswer;
                ptrAnswer = ptrAux;
                ptrAux = ptrExtra;
                
            } 
        }
        
        return *ptrAnswer;
    }
};