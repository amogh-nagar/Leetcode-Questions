class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<=2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int c=0;
        for(int i=0;i<nums.size()-2;i++){
            int k=i+1;
            for(int j=i+1;j<nums.size()-1 && nums[i]!=0;j++){
                
                while(k<nums.size() && (nums[i]+nums[j])>nums[k]){
                    k++;
                }
                c+=(k-j-1);
            }
        }
        return c;
    }
};