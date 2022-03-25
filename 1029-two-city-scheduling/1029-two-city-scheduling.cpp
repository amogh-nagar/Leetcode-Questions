class Solution {
public:
    // vector<vector<vector<int>>> dp;
    int dp[101][51][51];
    int solve(int a,int b,int i,vector<vector<int>>& c){
        if(i>=c.size()){
            return 0;
        }
        if(dp[i][a][b]!=-1){
            return dp[i][a][b];
        }
        int x=INT_MAX,y=INT_MAX;
        if(a>0){
            x=solve(a-1,b,i+1,c)+c[i][0];
        }
        if(b>0){
            y=solve(a,b-1,i+1,c)+c[i][1];
        }
        return dp[i][a][b]=min(x,y);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        // dp=vector<vector<vector<int>>> (n,vector<vector<int>>(n/2,vector<int>(n/2,-1)));
        memset(dp,-1,sizeof(dp));
        solve(n/2,n/2,0,costs);
        return dp[0][n/2][n/2];
    }
};