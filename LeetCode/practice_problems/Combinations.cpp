class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> answer;
        vector<vector<int>> tempAnswer;
        vector<vector<int>>* ptrAnswer = &answer;
        vector<vector<int>>* ptrTempAnswer = &tempAnswer;
        vector<vector<int>>* ptrTemp;
        
        vector<int> temp;
        vector<int> curr;
        int lastElement;
        int currSize;
        int tempCurrSize;

        for(int i = 1; i <= n-k+1; i++){
            temp = {i};
            ptrTempAnswer->push_back(temp);
        }

        int counter = 1;
        currSize = n-k+1;

        while(counter < k){            
            tempCurrSize = 0;
            for(int i = currSize-1; i >= 0; i--){
                curr = ptrTempAnswer->at(i);
                ptrTempAnswer->pop_back();
                
                lastElement = curr[curr.size()-1];
                
                for(int j = lastElement+1; j <= n-k+1+counter; j++){
                    temp = curr;
                    temp.push_back(j);
                    ptrAnswer->push_back(temp);
                    tempCurrSize++;
                }
            }
            if(counter == k-1)
                return *ptrAnswer;
            
            ptrTemp = ptrTempAnswer;
            ptrTempAnswer = ptrAnswer;
            ptrAnswer = ptrTemp;

            currSize = tempCurrSize;
            counter++;
        }

        return k != 1 ? *ptrAnswer : *ptrTempAnswer;
    }
};