class Solution {
public:
    int minSwaps(string s) {
         int cl=0,m=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                cl++;
            }
            else{
                cl--;
            }
            m=max(m,cl);
        }
        return (m+1)/2;
    }
};