class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=nums.size()-1;i>=0;i--){
           st.push(i);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=nums[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
};