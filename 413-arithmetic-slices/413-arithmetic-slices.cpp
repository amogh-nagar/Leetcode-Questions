class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int n=v.size();
        if(n<=2)
            return 0;
        int i=0,c=0,x=1,j=2,diff=(v[1]-v[0]);
        
        while(j<n){
            if(diff==(v[j]-v[j-1])){
                if((j-i+1)>=3){
                    c+=x;
                    x++;
                }
            }else{
                x=1;
                i=j-1;
            }
            diff=v[j]-v[j-1];
            j++;
        }
        return c;
    }
};