class Solution {
public:
    int pow(int x,int y){
        if(x==1 || x==0){
            return x;
        }
        x%=1337;
        int ans=1;
        while(y){
            if(y & 1){
                ans=(ans*x)%1337;
            }
            
            x=(x*x)%1337;
            y>>=1;
        }
        return ans;
    }
    
    int superPow(int a, vector<int>& b) {
        if(b.size()==0){
            return 1;
        }
        int x=b.back();
        b.pop_back();
        return (pow(superPow(a,b),10)*pow(a,x))%1337;
        
    }
};