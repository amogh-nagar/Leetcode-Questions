class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int curr,int mask,int mi,int dt,int player){
        if(dp[player][mask]!=-1){
            return dp[player][mask];
        }
        
        for(int i=1;i<=mi;i++){
            int nmask=(1<<(i-1));
            if(!(nmask & mask)){
                if(curr+i>=dt || !solve(curr+i,mask | nmask,mi,dt,(player+1)%2)){
                    return dp[player][mask]=true;
                }
            }
        }
        return dp[player][mask]=false;
    }
    bool canIWin(int mi, int dt) {
        if((mi*(mi+1))/2<dt)
            return false;
        
        dp=vector<vector<int>>(2,vector<int>(1<<mi,-1)); 
       int curr=0,mask=0;
       return solve(curr,mask,mi,dt,0);
    }
};