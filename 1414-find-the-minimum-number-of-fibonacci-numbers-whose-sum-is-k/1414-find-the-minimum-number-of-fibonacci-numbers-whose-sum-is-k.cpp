class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> v;
        v.push_back(1);v.push_back(1);
        
        int i=2;
        while(v[i-1]<k){
            v.push_back(v[i-1]+v[i-2]);
            i++;
        }
        int c=0;
        for(int j=i-1;j>=0;j--){
            if(k>=v[j]){
                k-=v[j];
                c++;
            }
            if(k==0)
                break;
        }
        return c;
        
    }
};