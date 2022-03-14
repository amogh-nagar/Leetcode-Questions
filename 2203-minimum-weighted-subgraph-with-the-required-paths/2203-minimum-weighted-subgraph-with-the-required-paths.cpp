class Solution {
public:
    typedef long long ll;
    vector<ll> dk(vector<vector<pair<int,int>>> graph,int src){
        queue<pair<ll,int>> q;
        int n=graph.size();
        vector<ll> des(n,INT64_MAX);
        q.push({0,src});
        des[src]=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(des[x.second]<x.first){
                continue;
            }
            for(auto y:graph[x.second]){
                if(des[y.first]>x.first+y.second){
                    des[y.first]=x.first+y.second;
                    q.push({des[y.first],y.first});
                }
            }
        }
        return des;
    }
    
    
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> graph(n),revgraph(n);
        for(auto i:edges){
            graph[i[0]].push_back({i[1],i[2]});
            revgraph[i[1]].push_back({i[0],i[2]});
        }
        vector<ll> dsrc1=dk(graph,src1);
        vector<ll> dsrc2=dk(graph,src2);
        vector<ll> ddest=dk(revgraph,dest);
        
        long long maxd=1e18;
        for(int i=0;i<n;i++){
            if(dsrc1[i]!=INT64_MAX && dsrc2[i]!=INT64_MAX && ddest[i]!=INT64_MAX)
            maxd=min(maxd,dsrc1[i]+dsrc2[i]+ddest[i]);
        }
        
        return maxd==1e18?-1:maxd;
    }
};