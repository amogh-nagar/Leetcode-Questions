class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if((m*n)!=original.size()){
            return {};
        }
        vector<vector<int>> res;
        int s=0;
        for(int i=0;i<original.size();i++){
            if((i-s+1)==n){
                res.push_back(vector<int>(original.begin()+s,original.begin()+i+1));
                s=i+1;
            }
        }
        return res;
    }
};