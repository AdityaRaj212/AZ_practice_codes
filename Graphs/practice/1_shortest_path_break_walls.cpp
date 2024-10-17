/*
Question:
You are given a graph of nxm where . represents floor, #represents wall, S represents starting
point and F represents finish point. In this question you have to find the minimum number of 
walls to be broken to reach F.
*/

#include<bits/stdc++.h>
#define F first 
#define S second 
#define MP make_pair
#define inf 1e18
#define int long long

using namespace std;
using state = pair<int,int>;

int n,m;
vector<vector<char>> arr;
vector<vector<int>> vis;
vector<vector<int>> dis;
state start,stop;

bool is_valid(int row, int col){
    return (row>=0 && row<n && col>=0 && col<m);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<state,int>> neighbours(state node){
    vector<pair<state,int>> neighs;
    for(int i=0;i<4;i++){
        int row = node.F + dy[i];
        int col = node.S + dx[i];

        if(is_valid(row,col)){
            if(arr[row][col]=='#'){
                neighs.push_back(MP(MP(row,col),1));
            }else{
                neighs.push_back(MP(MP(row,col),0));
            }
        }
    }
    return neighs;
}

void bfs01(state sc_node){
    vis[sc_node.F][sc_node.S] = 1;
    dis[sc_node.F][sc_node.S] = 0;
    deque<state> dq;
    dq.push_back(sc_node);

    while(!dq.empty()){
        state node = dq.front();
        dq.pop_front();

        for(auto v: neighbours(node)){
            if(!vis[v.F.F][v.F.S]){
                vis[v.F.F][v.F.S] = 1;
                dis[v.F.F][v.F.S] = min(dis[v.F.F][v.F.S],dis[node.F][node.S]+v.S);
                if(v.S==0){
                    dq.push_front(v.F);
                }else{
                    dq.push_back(v.F);
                }
            }
        }
    }
}

/*
6 6
S..#.F
.##...
......
##..##
######
..##..
*/

/*
6 6
S..#.F
###...
......
##..##
######
..##..
*/

void solve(){
    cin>>n>>m;
    
    arr.resize(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            arr[i][j] = s[j];
            if(arr[i][j]=='S'){
                start = MP(i,j);
            }else if(arr[i][j]=='F'){
                stop = MP(i,j);
            }
        }
    }

    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,inf));
    bfs01(start);

    cout<<dis[stop.F][stop.S]<<"\n";
}

signed main(){
    solve();
    return 0;
}