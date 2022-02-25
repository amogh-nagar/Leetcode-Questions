// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n,0);
	    int m=INT_MIN;
	    for(int i=0;i<n;i++){
	        int maxi=0;
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                maxi=max(maxi,dp[j]);
	            }
	        }
	        dp[i]=arr[i]+maxi;
	        m=max(m,dp[i]);
	    }
	   return m;    
	}  
	
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends