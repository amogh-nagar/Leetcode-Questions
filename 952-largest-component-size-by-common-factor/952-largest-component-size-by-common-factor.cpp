class Solution {
public:
    int parent[100001];
    int rank[100001];
    
    int findparent(int node){
        if(parent[node]==node){
            return node;
        }
        
        return parent[node]=findparent(parent[node]);
    }
    
    void unionp(int x,int y){
        x=findparent(x);
        y=findparent(y);
        if(x==y){
            return;
        }
        if(rank[x]>rank[y]){
               parent[y]=x;
        }else if(rank[x]<rank[y]){
               parent[x]=y;
           
        }else{
               parent[x]=y;
               rank[y]++;
           
        }
    }
    
    int largestComponentSize(vector<int>& nums) {
        for(int i=0;i<100001;i++){
            rank[i]=0;
            parent[i]=i;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=2;j<=sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    unionp(nums[i],j);
                    unionp(nums[i],nums[i]/j);
                }
            }
        }
        int maxsize=0;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
           int x=findparent(nums[i]);
            m[x]++;
            if(maxsize<m[x]){
                maxsize=m[x];
            }
           
        }
        return maxsize;
        
    }
};