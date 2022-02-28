class Solution {
public:
    bool check(string x,int i,int j){
        while(i<=j){
            if(x[i++]!=x[j--]){
                return false;
            }
        }
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        int l=0,h=a.length()-1;
        while(l<=h){
            if(a[l]!=b[h]){
                break;
            }
            l++;
            h--;
        }
        if(l>=h){
            return true;
        }
        bool x=check(a,l,h) || check(b,l,h);
        if(x){
            return true;
        }
        l=0,h=a.length()-1;
        while(l<=h){
            if(b[l]!=a[h]){
                break;
            }
            l++;
            h--;
        }
        
        if(l>=h){
            return true;
        }
        return check(a,l,h) || check(b,l,h);
    }
};