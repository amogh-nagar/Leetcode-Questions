class Solution {
public:
   
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n),res(n);
        vector<int> inde(n,0);
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            inde[x[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inde[i]==0){
                q.push(i);
            }
        }
        map<int,set<int>> m;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(auto c:g[x]){
                m[c].insert(x);
                for(auto y:m[x]){
                    m[c].insert(y);
                }
                inde[c]--;
                if(inde[c]==0){
                    q.push(c);
                }
            }
        }
        for(auto i:m){
            for(auto x:i.second){
               res[i.first].push_back(x);
            }
        }
        return res;
    }
};