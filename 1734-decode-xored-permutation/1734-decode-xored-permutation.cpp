class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int t=0;
        for(int i=0;i<encoded.size();i+=2){
            t^=encoded[i];
        }
        int n=encoded.size();
        for(int i=1;i<=n+1;i++){
            t^=i;
        }
        vector<int> v;
        v.push_back(t);
        
        for(int i=encoded.size()-1;i>=0;i--){
            v.push_back(t^encoded[i]);
            t=t^encoded[i];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};