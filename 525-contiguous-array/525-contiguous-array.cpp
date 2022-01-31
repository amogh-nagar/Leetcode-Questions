class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> m;
        int count=0,ma=0,n=nums.size();
        m[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count-=1;
            }
            else{
                count+=1;
            }
            
            if(m.find(count)!=m.end()){
                ma=max(ma,i-m[count]);
            }else{
               
            m[count]=i;   
            }
        }
        return ma;
    }
};