class Solution {
public:
    typedef long long int ll;
    long long maximumSubsequenceCount(string text, string pattern) {
        ll c1=0,c2=0;
        if(pattern[0]==pattern[1]){
            text+=pattern[1];
          ll c=0;
            c1=0;
        for(int i=0;i<text.length();i++){
            if(text[i]==pattern[1]){
                c+=c1;
                c1++;
            }
        }
            return c;
        }
        for(int i=0;i<text.length();i++){
            if(text[i]==pattern[0]){
                c1++;
            }else if(text[i]==pattern[1]){
                c2++;
            }
        }
        ll x= min(c1,c2);
        if(x==0){
            if(c1==0){
                return c2;
            }else{
                return c1;
            }
        }
        
        if(x==c1){
            text=pattern[0]+text;
        }
        else{
            text+=pattern[1];
        }
        ll c=0;
        c1=c2=0;
        for(int i=0;i<text.length();i++){
            if(text[i]==pattern[0]){
                c1++;
            }else if(text[i]==pattern[1]){
                c2++;
                c+=(c1);
            }
        }
        return c;
    }
};