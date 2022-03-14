class Solution {
public:
    
    void solve(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int n,int m,vector<vector<bool>> &visited,bool &x){
        
        
        visited[i][j]=true;
        if(grid1[i][j]!=grid2[i][j]){
            x=false;
        }
        
        if(i+1<n && grid2[i+1][j]==1 && !visited[i+1][j]){
            solve(i+1,j,grid1,grid2,n,m,visited,x);
        }
        if(j+1<m && grid2[i][j+1]==1 && !visited[i][j+1]){
            solve(i,j+1,grid1,grid2,n,m,visited,x);
        }
        if(i-1>=0 && grid2[i-1][j]==1 && !visited[i-1][j])
            solve(i-1,j,grid1,grid2,n,m,visited,x);
        if(j-1>=0 && grid2[i][j-1]==1 && !visited[i][j-1]){
            solve(i,j-1,grid1,grid2,n,m,visited,x);
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int c=0;
        int n=grid1.size(),m=grid1[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid2[i][j]==1){
                    bool x=1;
                    solve(i,j,grid1,grid2,n,m,visited,x);
                    if(x){
                      c++;        
                    }
                }
            }
        }
        return c;
    }
};