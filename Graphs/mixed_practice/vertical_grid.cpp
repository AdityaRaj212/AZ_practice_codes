#include<bits/stdc++.h>
#define F first 
#define S second 
#define MP make_pair

using namespace std;
using state = pair<int,int>;

int n,k;
int comp_size;
int comp_gt_k;
vector<vector<int>> arr;
vector<vector<int>> vis;
vector<state> members;

bool is_valid(int row, int col, int colour){
    return (row>=0 && row<n && col>=0 && col<10 && arr[row][col]==colour);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<state> neighbours(state node, int colour){
    vector<state> neighs;
    for(int i=0;i<4;i++){
        int row = node.F + dy[i];
        int col = node.S + dx[i];
        if(is_valid(row,col,colour)){
            neighs.push_back(MP(row,col));
        }
    }
    return neighs;
}

void gravity(){
    for(int j=0;j<10;j++){
        vector<int> col;
        for(int i=n-1;i>=0;i--){
            if(arr[i][j]!=0){
                col.push_back(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        int y = n-1;
        for(int i=0;i<col.size();i++){
            arr[y][j] = col[i];
            y--;
        }
    }
}

void dfs(state node, int colour){
    vis[node.F][node.S] = 1;
    members.push_back(node);
    comp_size++;
    for(auto v:neighbours(node, colour)){
        if(!vis[v.F][v.S]){
            vis[v.F][v.S] = 1;
            dfs(v,colour);
        }
    }
}

void solve(){
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++){
        arr[i].resize(10);
        string str;
        cin>>str;
        for(int j=0;j<10;j++){
            arr[i][j] = str[j]-'0';
        }
    }

    bool repeat = true;
    while(repeat){
        comp_gt_k = 0;
        vis.assign(n,vector<int>(10,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                int colour = arr[i][j];
                if(!vis[i][j] && is_valid(i,j,colour)){
                    comp_size = 0;
                    members.clear();
                    dfs(MP(i,j),colour);
                    // cout<<"Members of colour - "<<colour<<":"<<endl;
                    for(int i=0;i<members.size();i++){
                        if(comp_size>=k && arr[members[i].F][members[i].S] != 0){
                            comp_gt_k++;
                            arr[members[i].F][members[i].S] = 0;
                        }
                        // cout<<"("<<members[i].F<<","<<members[i].S<<"), ";
                    }
                    // cout<<"\nComponent size: "<<comp_size<<"\n\n";
                }
            }
        }
        if(comp_gt_k){    
            gravity();
            // cout<<"\nArray after first set of deletion:\n";
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<10;j++){
            //         cout<<arr[i][j];
            //     }
            //     cout<<endl;
            // }
        }else{
            repeat = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}

signed main(){
    solve();
    return 0;
}