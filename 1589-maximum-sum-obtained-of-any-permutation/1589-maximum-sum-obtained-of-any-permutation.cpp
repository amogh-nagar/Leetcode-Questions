class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int> indices(n,0);
        for(int i=0;i<requests.size();i++){
            indices[requests[i][0]]++;
            if(requests[i][1]+1<n){
                indices[requests[i][1]+1]--;
            }
        }
        for(int i=1;i<n;i++){
            indices[i]+=indices[i-1];
        }
        sort(indices.begin(),indices.end());
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum=(sum%1000000007+(((long long)indices[i]%(1000000007))*((long long)nums[i]%(1000000007)))%1000000007)%1000000007;         
        }
        return sum;
    }
};