// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> v(nums.begin(),nums.end());
	    sort(v.begin(),v.end());
	    map<int,int> m;
	    for(int i=0;i<nums.size();i++){
	        m.insert({nums[i],i});
	    }
	    int c=0;
	    vector<bool>visited(nums.size(),false);
	    for(int i=0;i<nums.size();i++){
	        if(v[i]!=nums[i] && !visited[i]){
	        int j=i;
	        int cc=0;
	        while(!visited[j]){
	            visited[j]=true;
	            j=m[v[j]];
	            
	            cc++;
	            
	        }
	        c+=(cc-1);
	        }
	    }
	    return c;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends