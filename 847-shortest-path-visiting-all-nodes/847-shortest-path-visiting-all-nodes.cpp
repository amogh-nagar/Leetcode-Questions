class Solution {
public:
    vector<vector<int>> dp;
   
    
    int solve(int mask,int node,vector<vector<int>>& graph){
        if(dp[node][mask]!=0){
            return dp[node][mask];
        }
        
        
        if((mask & (mask-1))==0){
            return 0;
        }
        
        dp[node][mask]=INT_MAX-1;
        for(auto x:graph[node]){
            if((mask & (1<<x))!=0){
                int alvis=solve(mask,x,graph);
                int notvis=solve(mask ^ (1<<node),x,graph);
                int btopt=min(alvis,notvis);
                dp[node][mask]=min(dp[node][mask],btopt+1);
            }
        }
        return dp[node][mask];
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
       
        int n=graph.size(); 
        int endingmask=(1<<n)-1;
        dp=vector<vector<int>>(n+1,vector<int>(endingmask+1,0));
    
        int best=INT_MAX;
        for(int i=0;i<n;i++){
            best=min(best,solve(endingmask,i,graph));
        }
        return best;
    }
};