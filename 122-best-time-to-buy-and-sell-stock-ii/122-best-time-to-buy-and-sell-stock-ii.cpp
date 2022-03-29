class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s=0;
        for(int i=0;i+1<prices.size();i++){
            if(prices[i]<prices[i+1]){
                s+=(prices[i+1]-prices[i]);
            }
        }
        return s;
    }
};