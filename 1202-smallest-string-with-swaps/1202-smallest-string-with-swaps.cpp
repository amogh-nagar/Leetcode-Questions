class Solution {
public:
    vector<char> res;
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)     {
        int n=s.length();
        vector<vector<int>> v(n);
        for(int i=0;i<pairs.size();i++){
            v[pairs[i][0]].push_back(pairs[i][1]);
            v[pairs[i][1]].push_back(pairs[i][0]);
        }
        res=vector<char>(n,0);
        string r;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
             if(!vis[i]){
                 string r;
        vector<int> id;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int x=q.front();q.pop();
            id.push_back(x);
            r+=s[x];
            for(auto t:v[x]){
                if(!vis[t]){
                    q.push(t);
                    vis[t]=1;
                }
            }
        }
        sort(id.begin(),id.end());
        sort(r.begin(),r.end());
        
        for(int i=0;i<id.size();i++){
            res[id[i]]=r[i];
        }
        
             }
        }
        for(int i=0;i<n;i++){
            r+=res[i];
        }
        return r;
    }
};