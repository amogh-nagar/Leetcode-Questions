class Solution {
public:
    int countSubstrings(string s, string t) {
        int n=s.length(),m=t.length();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=0;
                for(int k=0;i+k<n && j+k<m;k++){
                    if(s[i+k]!=t[j+k]){
                        x++;
                    }
                    
                    if(x>1){
                        break;
                        
                    }
                    ans+=x;    
                }
                
            }
        }
        return ans;
    }
};