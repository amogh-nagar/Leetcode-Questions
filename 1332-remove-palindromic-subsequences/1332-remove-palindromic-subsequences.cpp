class Solution {
public:
    int removePalindromeSub(string s) {
        int f=0;
        int l=0,h=s.length()-1;
        while(l<=h){
            if(s[l]!=s[h]){
                f=2;
                break;
            }
            l++;
            h--;
        }
        if(l>h){
            f=1;
        }
        return f;
    }
};