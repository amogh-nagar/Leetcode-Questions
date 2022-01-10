class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int carry=0;
        int i=a.length()-1,j=b.length()-1;
        for(;i>=0 && j>=0 ;i--,j--){
            int x=a[i]-'0'+b[j]-'0'+carry;
            carry=x/2;
            x=x==3?1:x==2?0:x;
            s=to_string(x)+s;
        }
        while(i>=0){
            int x=a[i]-'0'+carry;
            carry=x/2;
            x=x==2?0:x;
            s=to_string(x)+s;
            i--;
        }
        
        while(j>=0){
            int x=b[j]-'0'+carry;
            carry=x/2;
            x=x==2?0:x;
            s=to_string(x)+s;
            j--;
        }
        if(carry!=0){
            s='1'+s;
        }
        return s;
    }
};