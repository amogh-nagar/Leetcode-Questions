class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int j=0;j<l.size();j++){
            vector<int> t(nums.begin(),nums.end());
            sort(t.begin()+l[j],t.begin()+r[j]+1);
            int x=t[l[j]+1]-t[l[j]],f=0;
            for(int i=l[j]+2;i<=r[j];i++){
                if(t[i]-t[i-1]!=x){
                    ans.push_back(false);
                    f=1;break;
                }
            }
            if(!f){
                ans.push_back(true);
            }
        }
        return ans;
    }
};