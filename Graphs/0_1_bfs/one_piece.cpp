#include<bits/stdc++.h>
#define MP make_pair
#define F first 
#define S second 
#define inf 1e9

using namespace std;
using state = pair<int,int>;

int n,m;
vector<vector<int>> arr;
vector<vector<int>> vis;
vector<vector<int>> dis;

bool is_valid(int row, int col){
    return (row>0 && row<=n && col>0 && col<=m);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<state,int>> neighbours(state node, int direction){
    vector<pair<state,int>> neighs;
    for(int i=0;i<4;i++){
        int row = node.F + dy[i];
        int col = node.S + dx[i];
        if(is_valid(row,col)){

            int cost;
            if(dx[i]==1 && direction==1){
                cost = 0;
            }else if(dx[i]==-1 && direction==2){
                cost = 0;
            }else if(dy[i]==1 && direction==3){
                cost = 0;
            }else if(dy[i]==-1 && direction==4){
                cost = 0;
            }else{
                cost = 1;
            }

            neighs.push_back(MP(MP(row,col),cost));
        }
    }
    return neighs;
}

void _01_bfs(state node){
    vis[node.F][node.S] = 1;
    deque<state> q;
    q.push_back(node);
    dis[node.F][node.S] = 0;

    while(!q.empty()){
        state curr = q.front();
        q.pop_front();

        int direction = arr[curr.F][curr.S];
        for(auto v:neighbours(curr, direction)){
            state next_node = v.F;
            int cost = v.S;

            if(dis[next_node.F][next_node.S]>dis[curr.F][curr.S]+cost){
                dis[next_node.F][next_node.S]=dis[curr.F][curr.S]+cost;
                if(cost==0){
                    q.push_front(next_node);
                }else{
                    q.push_back(next_node);
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        arr[i].resize(m+1);
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    vis.assign(n+1,vector<int>(m+1,0));
    dis.assign(n+1,vector<int>(m+1,inf));
    state start = MP(1,1);
    state end = MP(n,m);

    _01_bfs(start);

    // cout<<"\nDis array: \n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dis[n][m]<<"\n";
}

signed main(){
    solve();
    return 0;
}