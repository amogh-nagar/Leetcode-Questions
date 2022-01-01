class Solution {
public:
    int t[1001][1001];
    int MCM(vector<int>& nums,int i,int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int mx = INT_MIN;
        for(int k=i;k<=j-1;k++){
            int temp = MCM(nums,i,k)+MCM(nums,k+1,j)+nums[i-1]*nums[k]*nums[j];
            mx = max(temp,mx);
        }
        return t[i][j] = mx;
    }
    int maxCoins(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        return MCM(nums,1,n-1);
    }
};