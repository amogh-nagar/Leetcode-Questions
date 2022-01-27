class Solution {
public:
    int numSteps(string s) {
        int j=0,c=0,i=s.length()-1;
        while(i!=0){
            if(s[i]=='0'){
                i--;
            }else{
                j=i;
                while(j>=0 && s[j]!='0' ){
                    s[j]='0';
                    j--;
                }
                if(j>=0 && s[j]=='0'){
                    s[j]='1';
                }else if(j<0){
                    s='1'+s;
                    i++;
                }
            }
            // cout<<s<<" "<<i<<endl;
            c++;
            // cout<<c<<endl;
        }
        return c;
    }
};