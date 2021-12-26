class Solution {
public:
    vector<int> solve(multiset<int> ms,int k){
        vector<int> ans;
        while(ms.size()!=0){
            auto it=ms.begin();
            int lmin=*it;
            int org=lmin+k;
            ms.erase(it);
            if(ms.find(org+k)!=ms.end()){
                ms.erase(ms.find(org+k));
                ans.push_back(org);
            }else{
                return {-1};
            }
        }
        return ans;
    }
    
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int smallest=nums[0];
        multiset<int> ms(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            int hadd=nums[i];
            int total=smallest+hadd;
            if(total%2==0){
                int org=total/2;
                int k=hadd-org;
                if(k==0){
                    continue;
                }
                vector<int> a=solve(ms,k);
                if(a[0]!=-1){
                    return a;
                }
            }
        }
        return {0};
    }
};