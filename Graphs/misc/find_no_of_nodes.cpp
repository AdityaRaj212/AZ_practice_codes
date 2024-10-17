#include<bits/stdc++.h>
using namespace std;

/*
5 4
1 2  
2 3 
3 5 
5 2
*/

vector<int> visited;
vector<vector<int>> edges;
int num_nodes;

void dfs(int node, int color){
    visited[node] = color;
    num_nodes++;
    for(auto v:edges[node]){
        if(!visited[v]){
            dfs(v,color);
        }
    }
}

void solve(){
    int nodes,edge;
    cin>>nodes>>edge;

    visited.resize(nodes+1);
    edges.resize(nodes+1);

    for(int i=0;i<edge;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int color = 1;
    vector<int> component_sizes;

    for(int i=1;i<=nodes;i++){
        if(!visited[i]){
            num_nodes = 0;
            dfs(i,color);
            component_sizes.push_back(num_nodes);
            color++;
        }
    }

    for(int i=1;i<=nodes;i++){
        cout<<visited[i]<<" ";
    }
    cout<<endl;
}

int main(){
    solve();
    return 0;
}