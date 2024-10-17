#include<bits/stdc++.h>
#define int long long
#define inf 1e9
#define F first 
#define S second 
#define MP make_pair
#define endl "\n"

using namespace std;
using state = pair<int,int>;

int n,m;
vector<vector<int>> g;
vector<vector<int>> vis;
vector<vector<int>> dis;

bool isValid(int row, int col){
    return (row>=0 && row<n && col>=0 && col<m && g[row][col]==1);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<state> neighbours(state node){
    vector<state> neighs;

    for(int i=0;i<4;i++){
        int row = node.F + dy[i];
        int col = node.S + dx[i];

        if(isValid(row, col)){
            neighs.push_back(MP(row, col));
        }
    }

    return neighs;
}

void multisource_bfs(vector<state> sources){
    queue<state> q;

    for(auto sc:sources){
        q.push(sc);
        dis[sc.F][sc.S] = 0;
        vis[sc.F][sc.S] = 1;
    }

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        for(auto v: neighbours(curr)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S] = 1;
                dis[v.F][v.S] = dis[curr.F][curr.S] + 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;

    vector<state> sources;

    g.resize(n);
    dis.resize(n);
    for(int i=0;i<n;i++){
        g[i].resize(m);
        dis[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>g[i][j];

            if(g[i][j]==2){
                sources.push_back(MP(i,j));
            }

            if(g[i][j]==1){
                dis[i][j] = -inf;
            }else{
                dis[i][j] = inf;
            }
        }
    }

    vis.assign(n, vector<int>(m, 0));

    multisource_bfs(sources);

    int ans = -inf;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(g[i][j]==1){
                if(dis[i][j]==-inf){
                    ans = -1;
                    break;
                }else{
                    ans = max(ans, dis[i][j]);
                }
           }
        }
    }

    cout<<ans<<endl;

}

signed main(){
    solve();
    return 0;
}