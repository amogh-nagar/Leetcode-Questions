class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n=nums.size();
        vector<int> inc(n,0),dec(n,0);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]>nums[i]){
                    dec[i]++;
                }else if(nums[j]<nums[i]){
                    inc[i]++;
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]>nums[i]){
                  c+=dec[j];    
                }
                else if(nums[j]<nums[i]){
                    c+=inc[j];
                }
            }
        }
        return c;
    }
};