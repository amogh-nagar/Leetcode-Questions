class Solution {
public:
    int nthUglyNumber(int n) {
       int i2=1,i3=1,i5=1;
        vector<int> v(n+1,0);
        v[1]=1;
        for(int i=2;i<=n;i++){
            int m2=v[i2]*2;
            int m3=v[i3]*3;
            int m5=v[i5]*5;
            
            v[i]=min(m2,min(m3,m5));
            if(v[i]==m2){
                i2++;
            }
            if(v[i]==m3){
                i3++;
            }
            if(v[i]==m5){
                i5++;
            }
        }
        return v[n];
    }
};