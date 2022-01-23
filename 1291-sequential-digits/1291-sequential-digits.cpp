class Solution {
public:
    
    
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        string x=to_string(low),y=to_string(high);
        int l=x.length();
        int h=y.length();
        vector<int> res;
        for(int i=l;i<=h;i++){
            for(int j=0;j<10-i;j++){
                int r=stoi(s.substr(j,i));
                if(r>=low && r<=high){
                    res.push_back(r);
                }
            }
        }
        return res;
    }
};