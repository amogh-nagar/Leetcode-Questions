class Solution {
public:
   
    double solve(map<string,vector<pair<string,double>>> m,vector<string> qi){
        queue<pair<string,double>> q;
        q.push({qi[0],1});
        unordered_set<string> s;
        while(!q.empty()){
            auto x=q.front();q.pop();
            s.insert(x.first);
            if(x.first==qi[1] && m.find(x.first)!=m.end()){
                return x.second;
            }
            for(auto y:m[x.first]){
                if(s.find(y.first)==s.end()){
                    q.push({y.first,(double)y.second*x.second});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> r(queries.size());
        map<string,vector<pair<string,double>>> m;
        for(int i=0;i<values.size();i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],(double)1/values[i]});
        }
        for(int i=0;i<queries.size();i++){
            r[i]=solve(m,queries[i]);
        }
        return r;
    }
};