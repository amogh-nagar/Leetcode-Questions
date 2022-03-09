class Solution {
public:
    int mask=0;
    int dp[(1<<15)][15];
    bool solve(vector<int>& v,int currsum,int asum,int k,int partition,int mask){
      int n=v.size();
        if(k==partition){
            if(mask == (1<<n)-1)
              return true;
            else
                return false;
        }   
        if(dp[mask][k]!=-1){
            return dp[mask][k];
        }
        int flag=0;
        for(int i=0;i<v.size();i++){
            if((mask & (1<<i))==0){
                if(currsum+v[i]<asum){
                    flag=solve(v,currsum+v[i],asum,k,partition,mask | (1<<i));
                    if(flag){
                        return true;
                    }
                }else if(currsum+v[i]==asum){
                    flag=solve(v,0,asum,k+1,partition,mask | (1<<i));
                    if(flag){
                        return true;
                    }
                }
            }
        }
        return dp[mask][k]=flag;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int i=0;i<matchsticks.size();i++){
            sum+=matchsticks[i];
        }
        if(sum%4!=0){
            return false;
        }
        sum/=4;
        memset(dp,-1,sizeof(dp));
        return solve(matchsticks,0,sum,0,4,0);
    }
};