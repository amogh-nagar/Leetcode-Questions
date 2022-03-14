class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,unordered_set<int>> m;
        for(auto i:logs){
            m[i[0]].insert(i[1]);
        }
        map<int,int> t;
        for(auto i:m){
            t[i.second.size()]++;
        }
        vector<int> res;
        for(int i=1;i<=k;i++){
            res.push_back(t[i]);
        }
        return res;
    }
};