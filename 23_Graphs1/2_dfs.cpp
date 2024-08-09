//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     void dfs(vector<int> adj[], vector<int> &visited, vector<int> &ans, int currIdx) {
        ans.push_back(currIdx); // Add the current node to the answer
        visited[currIdx] = 1; // Mark the current node as visited

        // Traverse all the neighbors of the current node
        for (auto neighbour : adj[currIdx]) {
            if (visited[neighbour] == 0) { // If the neighbor has not been visited yet
                dfs(adj, visited, ans, neighbour); // Perform DFS on the neighbor
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V, 0); // Vector to keep track of visited nodes
        vector<int> ans; // Vector to store the DFS traversal
        dfs(adj, visited, ans, 0); // Perform DFS starting from node 0
        return ans; // Return the DFS traversal
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends