class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        map<string,int> mp;
        
        for(int i=0;i<n;i++){
            string s(m,'T');
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=matrix[i][j-1]){
                    s[j]='F';
                }
            }
            mp[s]++;
        }
        int ans=0;
        for(auto x:mp){
            ans=max(ans,x.second);
        }
        return ans;
    }
};