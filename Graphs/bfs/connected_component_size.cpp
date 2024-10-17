#include<bits/stdc++.h>
#define F first
#define S second
#define MP make_pair

using namespace std;
using state = pair<int,int>;

int n,m;
int comp_size;
vector<vector<int>> arr;
vector<vector<int>> vis;
vector<vector<state>> parent;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_valid(int row, int col){
    if(row>=0 && row<n && col>=0 && col<m && arr[row][col]==0){
        return true;
    }
    return false;
}

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

void bfs(state node){
    vis[node.F][node.S] = 1;
    queue<state> q;
    q.push(node);
    parent[node.F][node.S] = MP(-1,-1);

    state last_node;

    while(!q.empty()){
        comp_size++;
        state curr = q.front();
        last_node = curr;
        q.pop();

        for(auto v:neighbours(curr)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S] = 1;
                parent[v.F][v.S] = curr;
                q.push(v);
            }
        }
    }

    while(last_node!=MP(-1,-1)){
        if(comp_size!=1){
            arr[last_node.F][last_node.S] = comp_size;
        }
        last_node = parent[last_node.F][last_node.S];
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n+1);
    for(int i=0;i<n;i++){
        arr[i].resize(m+1);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vis.assign(n+1,vector<int>(m+1,0));
    parent.assign(n+1,vector<state>(m+1,MP(-1,-1)));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && is_valid(i,j)){  // this loop is never executed
                // cout<<"comp size"<<endl;
                // cout<<"...y"<<comp_size<<"o..."<<endl;
                comp_size = 0;
                bfs(MP(i,j));
            }
        }
    }

    cout<<"Ans...."<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<"...";
        }
        cout<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    while(T--){
        arr.clear();
        vis.clear();
        parent.clear();
        solve();
    }
    return 0;
}