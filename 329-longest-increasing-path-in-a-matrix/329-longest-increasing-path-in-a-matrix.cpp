class Solution {
public:
    vector<vector<int>> dp;
    int maxi=0;
    vector<int> dr{1,-1,0,0};
    vector<int> dc{0,0,1,-1};
    bool issafe(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int solve(int i,int j,int n,int m,vector<vector<int>>& matrix){
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mi=1;
        for(int k=0;k<4;k++){
            int ni=dr[k]+i;
            int nj=dc[k]+j;
            if(issafe(ni,nj,n,m) && matrix[ni][nj]>matrix[i][j]){
                mi=max(mi,solve(ni,nj,n,m,matrix)+1);
            }
        }
        maxi=max(maxi,mi);
        return dp[i][j]=mi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        dp=vector<vector<int>> (n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                   solve(i,j,n,m,matrix);     
                }
            }
        }
        return maxi;
    }
};