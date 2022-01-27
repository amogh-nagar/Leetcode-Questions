class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)     {
        int n=arr.size();
        vector<int> prefixxor(n,0);
        prefixxor[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixxor[i]=prefixxor[i-1]^arr[i];
        }
        
        vector<int> v;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0){
                v.push_back(prefixxor[queries[i][1]]);
            }else{
                v.push_back(prefixxor[queries[i][0]-1] ^ prefixxor[queries[i][1]]);
            }
        }
        return v;
    }
};