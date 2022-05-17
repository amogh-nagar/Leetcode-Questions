class Solution {
public:
    vector<int> dr{1,1,1,-1,-1,-1,0,0};
    vector<int>dc{0,1,-1,0,1,-1,1,-1};
    vector<vector<bool>>  vis;    
    vector<vector<int>>  dp;
bool issafe(int n,int m,int i,int j){
        return i<n && i>=0 && j<m && j>=0;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        vis=vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size(),0));
        dp=vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int n=grid.size(),m=grid[0].size();
        dp[0][0]=1;
        while(!q.empty()){
            auto x=q.front();q.pop();
            vis[x.first][x.second.first]=1;
             for(int p=0;p<8;p++){
            int ni=x.first+dr[p];
            int nj=x.second.first+dc[p];
            if( issafe(n,m,ni,nj) &&!vis[ni][nj]  && grid[ni][nj]==0 && dp[ni][nj]>dp[x.first][x.second.first]+1){
                dp[ni][nj]=dp[x.first][x.second.first]+1;
                q.push({ni,{nj,x.second.second+1}});
            }
             }
        }
        return dp[n-1][m-1]==INT_MAX?-1:dp[n-1][m-1];
    }
};