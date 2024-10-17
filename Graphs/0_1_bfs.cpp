#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int n,m;
vector<vector<pair<int,int>>> edges;
vector<int> visited;
vector<int> dis;

void sssc(int source){
    visited.assign(n+1,0);
    dis.assign(n+1,INF);

    deque<int> dq;
    dq.push_back(source);
    dis[source] = 0;

    while(!dq.empty()){
        int x = dq.front();
        dq.pop_back();

        if(visited[x]) continue;
        visited[x] = 1;

        for(auto v:edges[x]){
            if(dis[v.first]>dis[x]+v.second){
                dis[v.first] = dis[x]+v.second;
                if(v.second==0){
                    dq.push_front(v.first);
                }
                else{
                    dq.push_back(v.first);
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    edges.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }

    int source;
    cin>>source;

    sssc(source);
    
    for(int i=1;i<=n;i++){
        cout<<i<<": "<<dis[i]<<endl;
    }
}

int main(){
    solve();
    return 0;
}




















// #include<bits/stdc++.h>
// #define INF 1e9
// using namespace std;

// int n,m;
// vector<vector<pair<int,int>>> edges;
// vector<int> visited;
// vector<int> dis;

// void sssc(int source){
//     visited.assign(n+1,0);
//     dis.assign(n+1,INF);

//     deque<int> dq;

//     dis[source] = 0;
//     dq.push_back(source);

//     while(!dq.empty()){
//         int x = dq.front();
//         dq.pop_back();

//         if(visited[x]) continue;
//         visited[x] = 1;

//         for(auto v:edges[x]){
//             if(dis[v.first]>dis[x]+v.second){
//                 dis[v.first] = dis[x]+v.second;
//                 if(v.second==0){
//                     dq.push_front(v.first);
//                 }
//                 else{
//                     dq.push_back(v.first);
//                 }
//             }
//         }
//     }
// }

// void solve(){
//     cin>>n>>m;
//     edges.resize(n+1);
//     visited.resize(n+1);
//     dis.resize(n+1);

//     for(int i=0;i<m;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         edges[a].push_back({b,c});
//         edges[b].push_back({a,c});
//     }

//     int source;
//     cin>>source;

//     sssc(source);

//     for(int i=1;i<=n;i++){
//         cout<<i<<": "<<dis[i]<<endl;
//     }
// }

// int main(){
//     solve();
//     return 0;
// }