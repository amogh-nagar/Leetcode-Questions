class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> g(n);
        for(auto i=0;i<edges.size();i++){
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<bool> vis(n,false);
        priority_queue<pair<double,int>> q;
        q.push({1.0,start});
        while(!q.empty()){
            auto x=q.top();q.pop();
            vis[x.second]=true;
            if(x.second==end){
                return x.first;
            }
            for(auto y:g[x.second]){
                if(!vis[y.first]){
                    q.push({(double)y.second*x.first,y.first});
                }
            }
        }
        return 0;
    }
};