class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,0),right(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }else{
                left[i]=st.top();
            }
            st.push(i);
        }
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=n;
            }else{
                right[i]=s.top();
            }
            
            s.push(i);
        }
        
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            m=max(m,(right[i]-left[i]-1)*heights[i]);
        }
        return m;
        
    }
};