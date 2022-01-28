class Solution {
public:
    vector<int> solve(int n){
       if(n==1){
           return {0,1};
       } 
        
        vector<int> v;
         vector<int> res=solve(n-1);
        for(int i=0;i<res.size();i++){
            v.push_back(res[i]);
            
        }
        for(int i=res.size()-1;i>=0;i--){
            v.push_back(1<<(n-1)|res[i]);
        }
        
        return v;
        
    }
    
    
    
    
    vector<int> grayCode(int n) {
          vector<int> res=solve(n);
        vector<int> v;
        for(auto x:res){
            // int i=stoi(x);
            v.push_back(x);
            // cout<<x<<endl;
        }
        return v;
    }
};