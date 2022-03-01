class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int c=0,j=0;
            while((1<<j)<=i){
                if(i & (1<<j)){
                    c++;
                }
                j++;
            }
            res.push_back(c);
        }
        return res;
    }
};