class Solution {
public:
    vector<vector<int>> dp;
     vector<vector<string>> ans;
    bool check(int i,int j,int n){
        for(int k=0;k<i;k++){
            if(dp[k][j]){
                return false;
            }
        }
        for(int k=i-1,m=j-1;k>=0 && m>=0 ;k--,m--){
            if(dp[k][m]){
                return false;
            }
        }
        for(int k=i-1,m=j+1;k>=0 && m<n ;k--,m++){
            if(dp[k][m]){
                return false;
            }
        }
        for(int k=i+1,m=j-1;k<n && m>=0 ;k++,m--){
            if(dp[k][m]){
                return false;
            }
        }
        for(int k=i+1,m=j+1;k<n && m<n ;k++,m++){
            if(dp[k][m]){
                return false;
            }
        }
        for(int k=i+1;k<n;k++){
            if(dp[k][j]){
                return false;
            }
        }
        return true;
    }
    void solve(int n,int i){
        if(i==n){
            vector<string> t;
            for(int i=0;i<n;i++){
                string s;
                for(int j=0;j<n;j++){
                    if(dp[i][j]){
                        s+='Q';
                    }else{
                        s+='.';
                    }
                }
                t.push_back(s);
            }
            ans.push_back(t);
            return;
        }
        for(int j=0;j<n;j++){
            if(check(i,j,n)){
                dp[i][j]=1;
                solve(n,i+1);
                dp[i][j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        dp=vector<vector<int>>(n,vector<int>(n,0));
        solve(n,0);
        return ans;
    }
};