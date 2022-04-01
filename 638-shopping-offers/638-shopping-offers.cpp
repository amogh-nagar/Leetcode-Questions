class Solution {
public:
    
    map<vector<int>,int> dp;
    int solve(vector<int> price, vector<vector<int>> special, vector<int> needs){
      
        if(dp[needs]!=0){
            return dp[needs];
        }
       int cost=INT_MAX,idx=0;
        for(idx=0;idx<needs.size();idx++){
            if(needs[idx]>0)
                break;
        }
        
        if(idx==needs.size()){
            return 0;
        }
       int t=price[idx]*needs[idx],p=needs[idx];
       needs[idx]=0;
       cost=min(cost,t+solve(price,special,needs));
       needs[idx]=p;  
      for(int i=0;i<special.size();i++){
          int f=0;
          for(int j=0;j<special[i].size()-1;j++){
              if(special[i][j]>needs[j]){
                  f=1;
                  break;
              }
          }
          if(!f){
              vector<int> temp(needs.begin(),needs.end());
              for(int j=0;j<needs.size();j++){
                  temp[j]-=special[i][j];
              }
              cost=min(cost,special[i][special[i].size()-1]+solve(price,special,temp));
          }
      }
        return dp[needs]=cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price,special,needs);
        
    }
};