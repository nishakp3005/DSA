#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adj ,vector<pair<int, int>> &edges){
    //adjacency list (assuming udirected graph) -->
    int u, v;
    for(int i = 0; i<edges.size(); i++){
        u = edges[i].first;
        v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void helper(vector<int> &ans, unordered_map<int, list<int>> &adj, unordered_map<int, bool> visited, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i : adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void print(vector<int> ans){
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout<<endl;
}

vector<int> BFS (vector<pair<int, int>> &edges){
    vector<int> ans;
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges);
    helper(ans, adj, visited, 0);
    print(ans);
    return ans;
}

int main(){
    vector<pair<int, int>> edges = {{0, 1},
                                    {0, 2},
                                    {1, 2},
                                    {0, 3}};
    // vector<pair<int, int>> edges = {{0, 1},
    //                                 {0, 2},
    //                                 {0, 3},
    //                                 {1, 4},
    //                                 {1, 7},
    //                                 {2, 5},
    //                                 {3, 6}};
    // vector<pair<int, int>> edges = {{0,1}, {0,2}, {0,3}};
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges);
    BFS(edges);
    return 0;
}