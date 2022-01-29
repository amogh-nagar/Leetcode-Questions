class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            for(int j=1;j<=i;j++){
                if(j==1 || i==j){
                    temp.push_back(1);
                continue;
                }
                else{
                temp.push_back(prev[j-1]+prev[j-2]);
                    }
            }
            prev=temp;
            res.push_back(temp);
        }
        return res;
    }
};