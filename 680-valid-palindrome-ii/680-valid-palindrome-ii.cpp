class Solution {
public:
    int solve(string s,int l,int h){
        while(l<=h){
            if(s[l++]!=s[h--]){
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int f=0,l=0,h=s.length()-1;
        while(l<=h){
            if(s[l]!=s[h]){
                f=1;
                break;
            }
            l++;
            h--;
        }
        if(!f){
            return true;
        }
        if(solve(s,l+1,h)|solve(s,l,h-1)){
            return true;
        }
        return false;
        
    }
};