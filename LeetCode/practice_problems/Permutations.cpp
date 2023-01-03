class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> aux;
        vector<vector<int>> curr;
        vector<vector<int>>* ptrAux = &aux;
        vector<vector<int>>* ptrCurr = &curr;
        vector<vector<int>>* ptrExtraAux;
        vector<int> currVector;
        vector<int> temp;
        int parity = 0;
        int currLength = 1;
        int currSize = 1;
        int tempCurrSize;

        curr.push_back({nums[0]});

        for(int i = 1; i < nums.size(); i++){
            tempCurrSize = currSize;
            //cout << currSize << endl;
            for(int j = 0; j < currSize; j++){
                currVector = ptrCurr->back();
                ptrCurr->pop_back();
                tempCurrSize--;

                for(int k = 0; k < currVector.size()+1; k++){
                    temp = currVector;
                    temp.insert(temp.begin()+k, nums[i]);
                    ptrAux->push_back(temp);
                    tempCurrSize++;
                }
            }
            ptrExtraAux = ptrAux;
            ptrAux = ptrCurr;
            ptrCurr = ptrExtraAux;
            currSize = tempCurrSize;
        }

        return *ptrCurr;
    }
};