class Solution {
public:
    int solve(vector<int>& a, vector<int>& b){
        int n=a.size(),m=b.size();
        int ans=0;
        for(int i=0;i<n+m-1;i++){
            int astart=max(0,n-1-i);
            int bstart=max(0,i-n-1);
            int l=0;
            for(int ai=astart,bi=bstart;ai<n && bi<m ; ai++,bi++){
                if(a[ai]==b[bi]){
                    l++;
                }else{
                    l=0;
                }
                ans=max(ans,l);
            }
        }
        return ans;
    }
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        
        return max(solve(nums1,nums2),solve(nums2,nums1));
    }
};