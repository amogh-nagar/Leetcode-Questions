class Solution {
public:
    bool static comp(pair<int,int> a,pair<int,int> b){
        return a.first==b.first?a.second<b.second:a.first<b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    c++;
                }
            }
            v.push_back({c,i});
        }
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};