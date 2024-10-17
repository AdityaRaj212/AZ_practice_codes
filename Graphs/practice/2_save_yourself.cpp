#include<bits/stdc++.h>
#define int long long
#define F first 
#define S second 
#define MP make_pair
#define endl "\n"
#define inf 1e9

using namespace std;
using state = pair<int,int>;

int n,m;
vector<vector<char>> arr;
vector<vector<int>> vis_monster;
vector<vector<int>> dis_monster;
vector<vector<int>> vis_person;
vector<vector<int>> dis_person;

bool isValid(int row, int col){
    return (row>=0 && row<n && col>=0 && col<m && arr[row][col]=='.');
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

    for(auto sc: sources){
        q.push(sc);
        vis_monster[sc.F][sc.S] = 1;
        dis_monster[sc.F][sc.S] = 0;
    }

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        for(auto v:neighbours(curr)){
            if(!vis_monster[v.F][v.S]){
                vis_monster[v.F][v.S] = 1;
                dis_monster[v.F][v.S] = dis_monster[curr.F][curr.S] + 1;
                q.push(v);
            }
        }
    }
}

void bfs(state node){
    queue<state> q;
    q.push(node);
    dis_person[node.F][node.S] = 0;
    vis_person[node.F][node.S] = 1;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        for(auto v:neighbours(curr)){
            if(!vis_person[v.F][v.S]){
                vis_person[v.F][v.S] = 1;
                dis_person[v.F][v.S] = dis_person[curr.F][curr.S] + 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;

    arr.resize(n);
    for(int i=0;i<n;i++){
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<state> sources;
    state start; 

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='M'){
                sources.push_back(MP(i,j));
            }
            if(arr[i][j]=='A'){
                start = MP(i,j);
            }
        }
    }

    vis_monster.assign(n, vector<int>(m, 0));
    dis_monster.assign(n, vector<int>(m, inf));
    vis_person.assign(n, vector<int>(m, 0));
    dis_person.assign(n, vector<int>(m, inf));

    multisource_bfs(sources);
    bfs(start);

    bool possible = false;
    int minDist = inf;

    for(int j=0;j<m;j++){
        if(dis_person[0][j]<dis_monster[0][j]){
            possible = true;
            minDist = dis_person[0][j];
            break;
        }
        if(dis_person[n-1][j]<dis_monster[n-1][j]){
            possible = true;
            minDist = dis_person[n-1][j];
            break;
        }
    }

    for(int i=1;i<n-1;i++){
        if(dis_person[i][0]<dis_monster[i][0]){
            possible = true;
            minDist = dis_person[i][0];
            break;
        }
        if(dis_person[i][m-1]<dis_monster[i][m-1]){
            possible = true;
            minDist = dis_person[i][m-1];
            break;
        }
    }

    if(possible){
        cout<<"YES"<<endl;
        cout<<minDist<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}

signed main(){
    solve();
    return 0;
}