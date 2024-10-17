//Method-I

// the worst case time complexity of this method is O(n^2) and this will be the case when
// all the given elements of the array are same.

#include<bits/stdc++.h>
#define MP make_pair
#define F first 
#define S second
#define inf 1e18
#define int long long

using namespace std;
using state = pair<int,int>;

int n;
int a,b;
int sc;
vector<int> arr;
vector<vector<int>> freq;
vector<vector<pair<int,int>>> g;
vector<int> dis;

bool is_valid(int row){
    return (row>=0 && row<n);
}

int dx[] = {-1,1};

void make_graph(){
    g.resize(n);
    for(int i=0;i<n;i++){
        int x1 = i;
        for(int j=0;j<2;j++){
            int x2 = x1 + dx[j];
            if(is_valid(x2)){
                g[x1].push_back(MP(x2,b));
            }
        }
        for(auto v:freq[arr[x1]]){
            g[x1].push_back(MP(v,a));
        }
    }
}

void dijkstra(int node){
    priority_queue<state> pq;
    pq.push(MP(-0,node));
    dis[node] = 0;

    while(!pq.empty()){
        state curr = pq.top();
        pq.pop();
        int curr_node = curr.S;
        for(auto v:g[curr_node]){
            int next_node = v.F;
            int cost = v.S;
            if(dis[next_node]>dis[curr_node]+cost){
                dis[next_node]=dis[curr_node]+cost;
                pq.push(MP(-dis[next_node],next_node));
            }
        }
    }
}

void solve(){
    cin>>n>>a>>b;
    arr.resize(n);
    freq.resize(101);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]].push_back(i);
    }

    make_graph();

    dis.assign(n+1,inf);
    cin>>sc;
    dijkstra(sc-1);

    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    solve();
    return 0;
}