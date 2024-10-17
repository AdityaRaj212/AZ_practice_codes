#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define F first 
#define S second 
#define MP make_pair
#define inf 1e18

using namespace std;
using state = pair<int,int>;

int n,m;
vector<vector<int>> g;
vector<vector<set<int>>> cols;
// vector<set<int>> cols;
vector<vector<int>> ans;

bool is_valid(int row, int col){
    return (row>=0 && row<n && col>=0 && col<m);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<state> neighbours(state node){
    vector<state> neighs;
    for(int i=0;i<4;i++){
        int row = node.F + dy[i];
        int col = node.S + dx[i];
        if(is_valid(row,col)){
            neighs.push_back(MP(row,col));
        }
    }
    return neighs;
}

state merge(state a, state b){
    if(cols[a.F][a.S].size()<cols[b.F][b.S].size()){
        state temp = a;
        a = b;
        b = temp;
    }

    for(auto v:cols[b.F][b.S]){
        cols[a.F][a.S].insert(v);
    }
    cols[b.F][b.S].clear();
    return a;
}

// int dfs(state node, state parent){
//     int curr_set = g[node.F][node.S];
//     for(auto v:neighbours(node)){
//         if(v.F!=parent.F && v.S!=parent.S){
//             curr_set = merge(curr_set,dfs(v,node));
//         }
//     }
//     ans[node.F][node.S] = curr_set;
//     return curr_set;
// }

state dfs(state node, state parent){
    state curr_set = node;
    for(auto v:neighbours(node)){
        if(v.F!=parent.F && v.S!=parent.S){
            curr_set = merge(curr_set,dfs(v,node));
        }
    }
    ans[node.F][node.S] = cols[curr_set.F][curr_set.S].size();
    return curr_set;
}

void solve(){
    cin>>n>>m;

    g.resize(n);
    cols.resize(n);
    ans.assign(n,vector<int>(m,-inf));
    int count = 0;
    for(int i=0;i<n;i++){
        g[i].resize(m);
        cols[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            cols[i][j].insert(g[i][j]);
            count++;
        }
    }

    int maxVal = -inf;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i][j]>maxVal){
                maxVal = ans[i][j];
            }
        }
    }
    cout<<maxVal<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}