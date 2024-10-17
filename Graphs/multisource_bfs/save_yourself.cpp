#include<bits/stdc++.h>
#define F first
#define S second
#define inf 1e9
#define MP make_pair
#define int long long

using namespace std;
using state = pair<int,int>;

int n,m;
vector<string> arr;
vector<vector<int>> vis;
vector<vector<int>> dis;
vector<vector<int>> vis_person;
vector<vector<int>> dis_person;

bool is_valid(state node){
    int row = node.F;
    int col = node.S;

    if(row>=0 && row<n && col>=0 && col<m && arr[row][col]!='#'){
        return true;
    }
    return false;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<state> neighbours(state node){
    vector<state> neighs;
    for(int i=0;i<4;i++){
        int row = node.F+dy[i];
        int col = node.S+dx[i];
        state neigh_node = MP(row,col);
        if(is_valid(neigh_node)){
            neighs.push_back(neigh_node);
        }
    }
    return neighs;
}

void multi_bfs(vector<state> sources){
    queue<state> q;
    for(auto s:sources){
        vis[s.F][s.S] = 1;
        dis[s.F][s.S] = 0;
        q.push(s);
    }

    while(!q.empty()){
        state curr = q.front();
        q.pop();

        for(auto v:neighbours(curr)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S] = 1;
                dis[v.F][v.S] = dis[curr.F][curr.S]+1;
                q.push(v);
            }
        }
    }
}

void bfs(state node){
    vis_person[node.F][node.S] = 1;
    queue<state> q;
    q.push(node);
    dis_person[node.F][node.S] = 0;

    while(!q.empty()){
        state curr = q.front();
        q.pop();

        for(auto v:neighbours(curr)){
            if(!vis_person[v.F][v.S]){
                vis_person[v.F][v.S] = 1;
                dis_person[v.F][v.S] = dis_person[curr.F][curr.S]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // cout<<"idhar";
        // string str;
        // cin>>str;
        // arr.push_back(str);
    }

    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,inf));

    vector<state> sources;
    state person;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='M'){
                sources.push_back(MP(i,j));
            }else if(arr[i][j]=='A'){
                person = MP(i,j);
            }
        }
    }

    multi_bfs(sources);

    vis_person.assign(n,vector<int>(m,0));
    dis_person.assign(n,vector<int>(m,inf));
    bfs(person);

    bool possible = false;
    int min_dist = inf;

    for(int j=0;j<m;j++){
        if(is_valid(MP(0,j))){
            if(dis_person[0][j]<dis[0][j]){
                possible = true;
                min_dist = dis_person[0][j];
                break;
            }
        }
        
        if(is_valid(MP(n-1,j))){
            if(dis_person[n-1][j]<dis[n-1][j]){
                possible = true;
                min_dist = dis_person[n-1][j];
                break;
            }
        }
    }
    for(int i=1;i<n-1;i++){
        if(is_valid(MP(i,0))){
            if(dis_person[i][0]<dis[i][0]){
                possible = true;
                min_dist = dis_person[i][0];
                break;
            }
        }
        if(is_valid(MP(i,m-1))){
            if(dis_person[i][m-1]<dis[i][m-1]){
                possible = true;
                min_dist = dis_person[i][m-1];
                break;
            }
        }
        
    }

    if(possible){
        cout<<"YES"<<"\n";
        cout<<min_dist<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    
    // cout<<"...Monster dis array..."<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // cout<<endl;
    // cout<<"...Person dis array..."<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dis_person[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
}

signed main(){
    solve();
    return 0;
}