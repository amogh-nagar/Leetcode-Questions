class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> res(heights.size(),0);
        res[heights.size()-1]=0;
        st.push(heights.size()-1);
        for(int i=heights.size()-2;i>=0;i--){
            if(!st.empty() && heights[st.top()]>heights[i]){
                res[i]=st.top()-i;
            }else{
                while(!st.empty() && heights[st.top()]<heights[i]){
                    res[i]++;
                    st.pop();
                }
                if(!st.empty())
                  res[i]++;
                
            }
            st.push(i);
        }
    return res;
    }
};