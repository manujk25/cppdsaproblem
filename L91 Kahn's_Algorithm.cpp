#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Time Complexity: O(V + E)
    // Space Complexity: O(V + E)
 
    vector<int> inDegree(v, 0);
    vector<vector<int>> adj(v);
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }   
    // Visited array
    vector<bool> visited(v, false);
    // Queue
    queue<int> q;
    // Put the nodes with indegree 0
    for(int i = 0; i < v; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    // store the final answer
    vector<int> ans;
    // BFS 
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        visited[curr] = true;
        for(int u : adj[curr]){
            if(visited[u]) continue;
            inDegree[u]--;
            if(inDegree[u] == 0) q.push(u);
        }
    }
        
    return ans;
}
