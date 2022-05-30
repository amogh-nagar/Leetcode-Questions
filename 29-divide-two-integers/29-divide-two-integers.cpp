class Solution {
public:
    
    typedef long long int ll;
    typedef long double ld;
    ll max(ll a , ll b){if(a > b) return a ; return b ;}
    ll min(ll a , ll b){if(a < b) return a ; return b ;}
    int divide(ll dividend,ll divisor) {
        int sign=1;
        if(dividend<0&&divisor>0 || dividend>0&&divisor<0)
            sign=-1;
        dividend=abs(dividend),divisor=abs(divisor);
        ll c=0,x=divisor;
        while(dividend&&dividend>=x){
            ll p=0,t=x;
            while(t<=dividend){
                if((t<<1)<=dividend)
                    t<<=1;
                else
                    break;
                p++;
            }
            if(p==31 && sign==-1){
                c+=(1<<p);
            }else if(p==31 && sign==1)
                c+=((ll)(1<<p)-1);
            else
                c+=(1<<p);
            dividend-=t;
        }
        return sign*(c);
    }
};