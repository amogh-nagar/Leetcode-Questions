// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {
       vector<long long int> v(n+1,0);
       
       for(int j=0;j<m;j++){
       
        for(int i=0;i<=n;i++){
           if(S[j]<=i){
               if(S[j]==i)
                 v[i]=v[i]+1;
               else 
                 v[i]=v[i]+v[i-S[j]];
           }
        }
           
       }
       return v[n];
        // code here.
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends