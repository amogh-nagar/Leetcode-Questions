class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<int> pref(n,0),left(n,n),right(n,n),res;
        left[0]=s[0]=='|'?0:n;
        for(int i=1;i<n;i++){
            if(s[i]=='|'){
                left[i]=i;
            }else{
                left[i]=left[i-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='|'){
                right[i]=i;
            }else if(i!=n-1 && s[i]!='|'){
                right[i]=right[i+1];
            }
        }
        pref[0]=s[0]=='*'?1:0;
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+(s[i]=='*');
        }
        n=queries.size();
        for(int i=0;i<n;i++){
            int l=queries[i][0];
            int r=queries[i][1];
                int x=right[l];
            int y=left[r];
            if(x!=left.size() && y!=left.size() && y>=x){
                res.push_back(pref[y]-pref[x]);
            
            }else{
                res.push_back(0);
            }
    
        }
        return res;
        
    }
};