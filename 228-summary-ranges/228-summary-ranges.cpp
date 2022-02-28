class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        vector<string> res;
        int s,e,n=nums.size();
        s=e=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-1!=e){
                if(s!=e)
                 res.push_back(to_string(s)+"->"+to_string(e));
                else
                 res.push_back(to_string(s));
            
                s=e=nums[i];
            }else{
                e=nums[i];
            }
        }
        if(s!=e)
        res.push_back(to_string(s)+"->"+to_string(e));
        else
        res.push_back(to_string(s));
            
        return res;
    }
};