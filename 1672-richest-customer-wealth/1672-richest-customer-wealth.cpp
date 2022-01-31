class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ma=0,m=accounts[0].size(),n=accounts.size();
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=0;j<m;j++){
                t+=accounts[i][j];
            }
            ma=max(ma,t);
        }
        return ma;
    }
};