class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        
        unsigned int x=~n;
        unsigned int m=~0;
        int c=0,t=x;
        // cout<<m<<" "<<x<<endl;
        while(t!=(~0)){
            // m=m<<1;
            t=t>>1;
            c++;
            // cout<<1<<endl;
        }
        m=~0;
        while(c!=0){
            m=m<<1;
            c--;
        }
        // cout<<m<<endl;
        return m^x;
    }
};