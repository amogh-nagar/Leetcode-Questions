class Solution {
public:
    bool static comp(pair<int,unordered_set<int>> a,pair<int,unordered_set<int>> b){
        return a.second.size()>b.second.size();
        
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graphs(n);
        for(int i=0;i<roads.size();i++){
            graphs[roads[i][0]].insert(roads[i][1]);
            graphs[roads[i][1]].insert(roads[i][0]);
        }
        pair<int,unordered_set<int>> v[n];
        for(int i=0;i<n;i++){
            v[i].first=i;
            v[i].second=graphs[i];
        }
        // sort(v,v+n,comp);
        int m=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x=v[i].second.size()+v[j].second.size();
                if(v[i].second.find(v[j].first)!=v[i].second.end() && v[j].second.find(v[i].first)!=v[j].second.end()){
                    x--;
                }
                m=max(m,x);
            }
        }
        return m;
    }
};