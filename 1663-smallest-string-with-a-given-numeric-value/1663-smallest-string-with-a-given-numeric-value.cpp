class Solution {
public:
    
    string getSmallestString(int n, int k) {
        string x(n,'a');
        k-=n;
        int i=n-1;
        while(k>0){
            x[i--]+=min(25,k);
            k-=min(25,k);
        }
        return x;
    }
};