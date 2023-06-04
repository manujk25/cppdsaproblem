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

// Approach 2 
    #include <bits/stdc++.h> 
    void dfsTopo(unordered_map<int,list<int>>&adj,vector<bool>&visited,stack<int>&s,int node){
    visited[node] = 1;


    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            dfsTopo(adj,visited,s,neighbour);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // preparing a adjacency list
    unordered_map<int,list<int>>adj;


    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];


        adj[u].push_back(v);
    }


    vector<bool>visited(v);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfsTopo(adj,visited,s,i);
        }
    }


    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }


    return ans;
}
