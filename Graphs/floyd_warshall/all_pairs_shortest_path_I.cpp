// Brute force algo

#include<bits/stdc++.h>
#define inf 1e18
#define int long long 

using namespace std;

int n;
vector<vector<int>> arr;
vector<vector<int>> dis;

void floyd_warshall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j] = arr[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

void sum(){
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]!=inf){
                ans += dis[i][j];
            }
        }
    }
    cout<<ans<<" ";
}

void solve(){
    cin>>n;
    arr.resize(n+1);
    dis.resize(n+1);
    for(int i=1;i<=n;i++){
        arr[i].resize(n+1);
        dis[i].resize(n+1);
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }

    floyd_warshall();
    sum();

    for(int i=0;i<n-1;i++){
        int a;
        cin>>a;
        for(int i=1;i<=n;i++){
            arr[i][a] = inf;
            arr[a][i] = inf;
        }
        floyd_warshall();
        sum();
    }
}

signed main(){
    solve();
    return 0;
}