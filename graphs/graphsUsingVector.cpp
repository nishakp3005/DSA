#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjacency(int n, int m, vector<vector<int>> &edges){
    vector<int> temp[n];
    int u, v;
    for(int i = 0; i<m; i++){
        u = edges[i][0];
        v = edges[i][1];
        temp[u].push_back(v);
        temp[v].push_back(u);
    }
    vector<vector<int>> ans(n);
    for(int i = 0; i<n; i++){
        cout<<i<<" - ";
        ans[i].push_back(i);
        for (int j = 0; j < temp[i].size(); j++){
            cout<<temp[i][j]<<" ";
            ans[i].push_back(temp[i][j]);
        }
        cout<<endl;
    }
    return ans;
}

int main(){
    int n, m;
    vector<vector<int>> edges = {{2, 1}, {2, 0}};
    adjacency(3, 2, edges);
    return 0;
}