class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++){
            s+=(i+'0');
        }
        
        while(k-->1){
            
            int i=n-2;
            while(i>=0 && s[i]>=s[i+1])
                i--;
            if(i>=0){
               int j=n-1;
               while(j>i && s[j]<=s[i]){
                j--;
               }
               swap(s[i],s[j]);
                
            }
            sort(s.begin()+i+1,s.end());
        }
        return s;
    }
};