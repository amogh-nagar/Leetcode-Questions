class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        if(target[0]!=1){
            int x=1;
            while(x!=target[0]){
                res.push_back("Push");res.push_back("Pop");
                    x++;
            }
            
            res.push_back("Push");
        }else{
            res.push_back("Push");
        }
        for(int i=1;i<target.size();i++){
            if(target[i]-1!=target[i-1]){
                int x=target[i]-target[i-1]-1;
                while(x!=0){
                    res.push_back("Push");res.push_back("Pop");
                    x--;
                }
                            res.push_back("Push");

            }else{
                res.push_back("Push");
            }
        }
        
        return res;
    }
};