class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l=0,h=people.size()-1,ans=0;
        sort(people.begin(),people.end());
        while(l<=h){
           int x=people[l]+people[h];
           if(x<=limit){
               ans++;
               l++;
               h--;
           } 
           else{
               ans++;
               h--;
           } 
        
        }
        return ans;
    }
};