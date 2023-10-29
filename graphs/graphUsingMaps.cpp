#include<bits/stdc++.h>
using namespace std;

class graph{

    public:

    map<int, list<int>> adj;

    void edge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i : adj){
            cout<<i.first<< " -> ";
            for(auto j : i.second){
                cout<< j <<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    graph g;
    int n;
    cout<<"enter the number of nodes : ";
    cin>>n;
    int m;
    cout<<"enter the number of edges : ";
    cin>>m;
    int u, v;
    for (int j = 0; j < m; j++){
        cin>>u>>v;
        g.edge(u,v, false);
    }
    g.print();
    return 0;
}