class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> v(n+1);
        for(auto x:trust){
            v[x[0]].push_back(x[1]);
        }
        int x=0;
        for(int i=1;i<n+1;i++){
            if(v[i].size()==0){
                x=i;
            }
        }
        if(x==0){
            return -1;
        }
        for(int i=1;i<n+1;i++){
            if(i==x){
                continue;
            }
            if(!count(v[i].begin(),v[i].end(),x)){
                return -1;
            }
        }
        return x;
    }
};