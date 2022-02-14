class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(__gcd(i,j)==1 && j!=1 && i<j){
                    res.push_back(to_string(i)+"/"+to_string(j));
                }
            }
        }
        return res;
        
    }
};