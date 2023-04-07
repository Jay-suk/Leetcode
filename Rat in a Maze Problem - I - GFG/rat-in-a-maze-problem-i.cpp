//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int size;
    vector<string> ans;
    
    bool isBadCell(int row,int col)
    {
        return (row<0 || col<0 || row>=size || col>=size);
    }
    
    void dfs(int row,int col,string curr,vector<vector<int>> &maze,vector<vector<bool>> &vis)
    {
        if(isBadCell(row,col) || maze[row][col]==0 || vis[row][col])
            return;
        if(row==size-1 && col==size-1)
        {
            ans.push_back(curr);
            return;
        }
        
            
        vis[row][col]=true;
        
        dfs(row+1,col,curr+'D',maze,vis);
        dfs(row-1,col,curr+'U',maze,vis);
        dfs(row,col+1,curr+'R',maze,vis);
        dfs(row,col-1,curr+'L',maze,vis);
        
        vis[row][col]=false;
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        size=n;
        string curr="";
        
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int row=0,col=0;
        dfs(row,col,curr,maze,vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends