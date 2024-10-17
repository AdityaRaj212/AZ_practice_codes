#include<bits/stdc++.h>
#define inf 1e9
#define F first 
#define S second 
#define MP make_pair

using namespace std;
using state = pair<int,int>;

int n,m;
vector<vector<int>> arr;
vector<vector<int>> vis;
vector<vector<int>> dis;
vector<state> sources;

bool is_valid(int row, int col){
    return (row>=0 && row<n&& col>=0 && col<m && arr[row][col]!=0);
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<state> neighbours(state node){
    vector<state> neighs;
    for(int i=0;i<4;i++){
        int row = node.F+dy[i];
        int col = node.S+dx[i];
        if(is_valid(row,col)){
            neighs.push_back(MP(row,col));
        }
    }
    return neighs;
}

void bfs(vector<state> sources){
    queue<state> q;
    for(auto src: sources){
        vis[src.F][src.S] = 1;
        dis[src.F][src.S] = 0;
        q.push(src);
    }

    while(!q.empty()){
        state curr = q.front();
        q.pop();

        for(auto v: neighbours(curr)){
            if(!vis[v.F][v.S]){
                q.push(v);
                vis[v.F][v.S] = 1;
                dis[v.F][v.S] = dis[curr.F][curr.S]+1;
            }
        }
    }
}

void solve(){   
    cin>>n>>m;
    arr.resize(n+1);
    vector<state> sources;
    for(int i=0;i<n;i++){
        arr[i].resize(m+1);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                sources.push_back(MP(i,j));
            }
        }
    }

    vis.assign(n+1,vector<int>(m+1,0));
    dis.assign(n+1,vector<int>(m+1,-1));

    bfs(sources);

    int maxDist = 0;
    bool possible = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dis[i][j]==-1 && arr[i][j]==1){
                possible = false;
                break;
            }
            if(dis[i][j]>maxDist){
                maxDist = dis[i][j];
            }
        }
        if(!possible){
            break;
        }
    }
    if(possible){
        cout<<maxDist<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}

signed main(){
    solve();
    return 0;
}