class Solution {
public:
    int explore(vector<pair<int,int>>& count,vector<vector<vector<int>>> &dp,int m,int n,int i)
    {
        if(m<0||n<0)
            return -1;
        if(i==count.size()||(m==0&&n==0))
        {
            return 0;
        }
    
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int ans=0;
        //We have Two option 
        
        //1) Take current one
            ans=max(ans,1+explore(count,dp,m-count[i].first,n-count[i].second,i+1));
        
        //2)Don't take the current one 
        
            ans=max(ans,explore(count,dp,m,n,i+1));
        
        
        return dp[i][m][n]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> count;
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<strs.size();i++)
        {
            int count0=0;
            int count1=0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0')
                {
                    count0++;
                }
                else
                {
                    count1++;
                }
            }
            count.push_back({count0,count1});
        }
        
        return explore(count,dp,m,n,0);
        
    }
};