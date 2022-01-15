class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> ans(n,0);
        int c=0,t=0;
        for(int i=0;i<n;i++){
            ans[i]=t;
            c+=(boxes[i]-'0');
            t+=c;
        }
        c=0,t=0;
        for(int i=n-1;i>=0;i--){
            ans[i]+=t;
            c+=(boxes[i]-'0');
            t+=c;
        }
        return ans;
    }
};