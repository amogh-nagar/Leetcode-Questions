class Solution {
public:
        int find(vector<int>&nums,int K,int p)
    {
        int n=nums.size();
        int count=0;
        set<string>s;
        for(int i=0;i<n;i++)
        {
            int val=0;
            string str="";
            for(int j=i;j<n;j++)
            {
                val+=(nums[j]%p==0);
                if(val>K)
                {
                   break;
                }
                str+=nums[j];
                s.insert(str);
            }
        }
        return s.size();
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        return find(nums,k,p);
    }

};