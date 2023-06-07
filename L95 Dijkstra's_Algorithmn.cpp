#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }
    set<pair<int,int> > st;

    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto i: adj[topNode]){
            if(nodeDist + i.second < dist[i.first]){

                auto record = st.find(make_pair(dist[i.first], i.first));

                if(record != st.end()){
                    st.erase(record);
                }

                dist[i.first] = nodeDist + i.second;

                st.insert(make_pair(dist[i.first], i.first));

            }
        }
    }
    return dist;

}

// method 2
#include <bits/stdc++.h> 
void MakeList(vector<vector<int>> &vec,unordered_map<int,list<pair<int,int>>>&adjlist){
    for(int i=0;i<vec.size();i++){
        int u= vec[i][0];
        int v= vec[i][1];
        int weight =vec[i][2];
        adjlist[u].push_back({v,weight});
        adjlist[v].push_back({u,weight});
    }
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adjlist;
    MakeList(vec,adjlist);
    vector<int>dist(vertices,INT_MAX);
    set<pair<int,int>> st;
    dist[source]=0;
    st.insert({0,source});
    while(!st.empty()){
        //fetch the top record
        pair<int,int> front= *(st.begin());
        st.erase(st.begin());
        for(auto i: adjlist[front.second] ){
            if(front.first + i.second < dist[i.first]){
                dist[i.first]= front.first + i.second;
                st.insert({dist[i.first],i.first});
            }
        }
    }
    return dist;
}
