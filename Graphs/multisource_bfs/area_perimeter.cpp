#include<bits/stdc++.h>
#define F first 
#define S second 
#define MP make_pair
#define inf 1e9

using namespace std;
using state = pair<int,int>;

int n;
int compSize;
vector<vector<char>> arr;
vector<vector<int>> vis;
vector<int> perimeter;
vector<int> comp_size;

bool is_valid(int row, int col){
    return (row>=0 && row<n && col>=0 && col<n && arr[row][col]=='#');
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<state> neighbours(state node, int colour){
    vector<state> neighs;
    for(int i=0;i<4;i++){
        int row = node.F + dy[i];
        int col = node.S + dx[i];

        if(is_valid(row,col)){
            neighs.push_back(MP(row,col));
        }else{
            perimeter[colour]++;
        }
    }
    return neighs;
}

void bfs(state node, int colour){
    vis[node.F][node.S] = colour;
    queue<state> q;
    q.push(node);
    compSize = 1;

    while(!q.empty()){
        state curr = q.front();
        q.pop();
        
        for(auto v:neighbours(curr,colour)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S] = colour;
                compSize++;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        arr[i].resize(n+1);
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    vis.assign(n,vector<int>(n,0));
    perimeter.assign(n*n,0);
    comp_size.assign(n*n,0);

    int colour = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && is_valid(i,j)){
                colour++;
                bfs(MP(i,j),colour);
                comp_size[colour] = compSize;
            }
        }
    }
    
    int max_area = 0;
    vector<int> min_peri;
    
    for(int i=1;i<=colour;i++){
        if(comp_size[i]>max_area){
            max_area = comp_size[i];
        }
    }
    
    for(int i=1;i<=colour;i++){
        if(comp_size[i]==max_area){
            min_peri.push_back(perimeter[i]);
        }
    }
    
    int minPeri = inf;
    for(int i=0;i<min_peri.size();i++){
        if(min_peri[i]<minPeri){
            minPeri = min_peri[i];
        }
    }
    
    cout<<max_area<<" "<<minPeri<<"\n";

    // cout<<"Component size : Perimeter"<<endl;
    // for(int i=1;i<=colour;i++){
    //     if(comp_size[i]!=0){
    //         cout<<comp_size[i]<<" : "<<perimeter[i]<<"\n";
    //     }
    // }
}

int main(){
    solve();
    return 0;
}