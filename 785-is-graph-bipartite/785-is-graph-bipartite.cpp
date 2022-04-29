class Solution {
public:
    bool solve(int node,vector<bool> &vis,vector<vector<int>>& graph,vector<int> &col){
       queue<int> q;
       q.push(node);
        col[node]=1;
        while(!q.empty()){
            int x=q.front();q.pop();
            vis[x]=1;
            cout<<x<<" ";
            for(auto y:graph[x]){
                if(!vis[y]){
                    col[y]=col[x]*-1;
                    q.push(y);
                }else if(col[y]==col[x]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<int> col(n,0);
        bool t=true;
        for(int i=0;i<n;i++){
           if(!vis[i]){
            t&=solve(i,vis,graph,col);
           }   
        }
        return t;
    }
};