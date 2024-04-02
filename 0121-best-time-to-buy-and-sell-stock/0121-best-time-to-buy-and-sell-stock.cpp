class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxCur = 0, maxSoFar = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            maxCur = std::max(0, maxCur + prices[i] - prices[i - 1]);
            maxSoFar = std::max(maxSoFar, maxCur);
        }
        
        return maxSoFar;
    }
};
