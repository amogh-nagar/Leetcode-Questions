class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0){
            return {0};
        }
        if(n==1){
            return {0,1};
        }
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        for(int i=2;i<=n;i++){
            int c2=log2(i);
            c2=(1<<c2);
            res.push_back(res[i-c2]+1);
            
        }
        return res;
    }
};