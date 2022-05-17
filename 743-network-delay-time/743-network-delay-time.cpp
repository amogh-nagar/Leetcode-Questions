class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(auto x:times){
            g[x[0]].push_back({x[1],x[2]});
        }
        queue<int> q;
        q.push(k);
        vector<int> vis(n+1,INT_MAX);
        vis[k]=0;        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            for(auto y:g[t]){
                if(vis[y.first]>vis[t]+y.second){
                    vis[y.first]=vis[t]+y.second;
                    q.push(y.first);
                }
            }
        }
        if(*max_element(vis.begin()+1,vis.end())==INT_MAX)
            return -1;
        return *max_element(vis.begin()+1,vis.end());
    }
};