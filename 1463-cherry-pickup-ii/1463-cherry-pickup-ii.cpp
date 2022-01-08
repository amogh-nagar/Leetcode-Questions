class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
    int dp[n][m][m];
        memset(dp,-1,sizeof(dp));
       for(int row=n-1;row>=0;row--){
            for(int col1=0;col1<m;col1++){
                for(int col2=0;col2<m;col2++){
                    
        int res=0;
        res+=grid[row][col1];
        if(col1!=col2){
            res+=grid[row][col2];
        }
        if(row!=n-1){
        int maxi=0;
            for(int n1=col1-1;n1<=col1+1;n1++){
            for(int n2=col2-1;n2<=col2+1;n2++){
                if(n1>=0 && n2>=0 && n1<m && n2<m){
                maxi=max(maxi,dp[row+1][n1][n2]);}
            }
        }
         res+=maxi;
        }
    dp[row][col1][col2]=res;
 
                }
            }
        }
        return dp[0][0][m-1];

    }
};