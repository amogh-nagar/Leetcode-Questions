class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> m;
        int c=0,s=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            c+=(nums[i]%2);
            if(m[c-k]!=0){
                s+=m[c-k];
            }
            m[c]++;
        }
        return s;
    }
};