class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<bool>>& visited){
        if(grid[i][j]==0 || visited[i][j]){
            return 0;
        }
        visited[i][j]=true;
        int x=0;
        if(i+1<n && !visited[i+1][j]){
            x=max(x,dfs(grid,i+1,j,n,m,visited));
        }
        if(i-1>=0 && !visited[i-1][j]){
            x=max(x,dfs(grid,i-1,j,n,m,visited));
        }
        if(j+1<m && !visited[i][j+1]){
            x=max(x,dfs(grid,i,j+1,n,m,visited));
        }
        if(j-1>=0 && !visited[i][j-1]){
            x=max(x,dfs(grid,i,j-1,n,m,visited));
        }
        visited[i][j]=false;
        return x+grid[i][j];
        
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        int x=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                x=max(x,dfs(grid,i,j,n,m,visited));     
            }
        }
        return x;
    }
};