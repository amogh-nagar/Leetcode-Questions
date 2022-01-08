class Solution {
public:
    
    
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        for(auto x:words){
            m[x]++;
        }
        int f=0,c=0;
        
        for(auto x:m){
            string y=x.first;
            string r=y;
            reverse(r.begin(),r.end());
            if(y==r){
              c+=(m[y]/2);
              if(m[y]%2){
                  f=1;
              }  
            }else{
                int l=(min(m[y],m[r]));
                m[y]-=l;
                m[r]-=l;
                c+=l;
            }
        }
        c*=4;
        if(f){
            c+=2;
        }
        return c;
    }
};