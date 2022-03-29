class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff=0,mint=prices[0];
        for(int i=1;i<prices.size();i++){
            if(diff<(prices[i]-mint)){
                diff=prices[i]-mint;
            }
            mint=min(mint,prices[i]);
        }
        return diff;
    }
};