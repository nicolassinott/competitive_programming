class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxDif = 0;
        int currMin = 200000;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < currMin)
                currMin = prices[i];
            maxDif = max(maxDif, prices[i] - currMin);
        }

        return maxDif;
    }
};