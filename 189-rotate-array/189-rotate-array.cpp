class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> t(n,0);
        for(int i=0;i<n;i++){
            t[(i+k)%n]=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=t[i];
        }
    }
};