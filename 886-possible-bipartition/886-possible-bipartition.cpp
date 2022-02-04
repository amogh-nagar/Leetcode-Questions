class Solution {
public:
    bool bfs(vector<vector<int>> graph,int n,vector<int>&colors){
        
        queue<int> q;
        q.push(n);
        colors[n]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:graph[x]){
                
                if(colors[y]==-1){
                  colors[y]=1-colors[x];
                    q.push(y);
                }else if(colors[y]==colors[x]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> colors(n+1,-1);
        vector<vector<int>> graph(n+1);
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(colors[i]==-1){
              
            if(!bfs(graph,i,colors)){
                return false;
            }   
            }
        }
        return true;
    }
};