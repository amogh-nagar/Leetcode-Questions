// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int mi=INT_MAX,x=0,i=0,j=0;
        int c=0,b=0;
        for(int l=0;l<n;l++){
            if(arr[l]<=k){
                c++;
            }
            
        }
        for(int i=0;i<c;i++){
            if(arr[i]>k){
                b++;
            }
        }
        if(c==n||c<=1){
            return 0;
        }
        mi=b;
        for(int i=0,j=c;j<n;i++,j++){
            if(arr[i]>k){
                b--;
            }
            if(arr[j]>k){
                b++;
            }
            mi=min(mi,b);
        }
        return mi;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends