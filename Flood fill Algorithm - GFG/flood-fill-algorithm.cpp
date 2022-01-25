// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        queue<pair<int,int>> q;
        int n=image.size(),m=image[0].size();
        vector<vector<bool>> v(n,vector<bool>(m,false));
        q.push({sr,sc});
        int x=image[sr][sc];
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first,j=p.second;
            image[i][j]=newColor;
            v[i][j]=true;
            if(i-1>=0 && image[i-1][j]==x && !v[i-1][j]){
                q.push({i-1,j});
                v[i-1][j]=1;
            }
            if(j-1>=0 && image[i][j-1]==x && !v[i][j-1]){
                q.push({i,j-1});
                v[i][j-1]=1;
            }
            if(i+1<n && image[i+1][j]==x && !v[i+1][j]){
                q.push({i+1,j});
                v[i+1][j]=1;
            }
            if(j+1<m && image[i][j+1]==x && !v[i][j+1]){
                q.push({i,j+1});
                v[i][j+1]=1;
            }
        }
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends