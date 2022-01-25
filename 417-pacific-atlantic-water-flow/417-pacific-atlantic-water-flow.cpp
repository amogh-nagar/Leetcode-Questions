class Solution {
public:
    vector<vector<int>> p;
    vector<vector<int>> q;
    vector<vector<int>> res;
    void dfs(int i,int j,int n,int m,vector<vector<int>>&t,vector<vector<int>> h,int prev){
        if(t[i][j]!=-1){
            return;
        }
        t[i][j]=1;
        if(p[i][j]==1 && q[i][j]==1){
            res.push_back({i,j});

        }
        if(i+1<n  && t[i+1][j]==-1 && h[i+1][j]>=h[i][j])
           dfs(i+1,j,n,m,t,h,h[i][j]);
        if(j+1<m  && t[i][j+1]==-1 && h[i][j+1]>=h[i][j])
           dfs(i,j+1,n,m,t,h,h[i][j]);
        if(i-1>=0 && t[i-1][j]==-1 && h[i-1][j]>=h[i][j])
           dfs(i-1,j,n,m,t,h,h[i][j]);
        if(j-1>=0 && t[i][j-1]==-1 && h[i][j-1]>=h[i][j])
           dfs(i,j-1,n,m,t,h,h[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        p=q=vector<vector<int>> (n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            dfs(i,0,n,m,p,heights,-1);
            dfs(i,m-1,n,m,q,heights,-1);
        }
        
        for(int i=0;i<m;i++){
            dfs(0,i,n,m,p,heights,-1);
            dfs(n-1,i,n,m,q,heights,-1);
        }
        
        
        return res;
    }
};