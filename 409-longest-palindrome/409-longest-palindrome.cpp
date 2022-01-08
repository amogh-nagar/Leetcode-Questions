class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(auto x:s){
            m[x]++;
        }
        int c=0,f=0;
        for(auto i:m){
            if(i.second%2==0){
                c+=i.second;
            }else{
                if(f==0){
                    c+=i.second;
                    f=1;
                }else{
                    c+=(i.second-1);
                }
            }
        }
        return c;
    }
};