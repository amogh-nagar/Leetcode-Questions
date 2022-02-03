class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int s=0;
        for(int i=31;i>=0;i--){
            int x=1<<i;
            if(x & right){
                if(left>x){
                    s|=(x);
                }else if(left==x){
                    return x;
                }else if(left<x){
                    return 0;
                }
                break;
            }
        }
        long long int x=left;
        for(long long int i=left;i<=right;i++){
            x&=i;
        }
        return x;
        
    }
};