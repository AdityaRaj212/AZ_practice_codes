//optimised algo

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dis;
vector<int> ans;
vector<int> nodes;

void floyd_warshall(){
    for(int k=n;k>0;k--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][nodes[k]]+dis[nodes[k]][j]);
            }
        }
        int temp_ans = 0;
        for(int i=k;i<=n;i++){
            for(int j=k;j<=n;j++){
                temp_ans += dis[nodes[i]][nodes[j]];
            }
        }
        ans.push_back(temp_ans);
    }
}

void solve(){
    cin>>n;
    dis.resize(n+1);
    for(int i=1;i<=n;i++){
        dis[i].resize(n+1);
        for(int j=1;j<=n;j++){
            cin>>dis[i][j];
        }
    }
    nodes.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>nodes[i];
    }

    floyd_warshall();

    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    solve();
    return 0;
}