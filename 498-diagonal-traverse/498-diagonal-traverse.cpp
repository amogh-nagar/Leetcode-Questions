class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> v;
        map<int,vector<int>> mm;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mm[i+j].push_back(mat[i][j]);
            }
        }
        for(auto x:mm){
            if(x.first%2==0){
                reverse(x.second.begin(),x.second.end());
                
            }
            for(auto y:x.second){
                v.push_back(y);
            }
        }
        return v;
    }
};