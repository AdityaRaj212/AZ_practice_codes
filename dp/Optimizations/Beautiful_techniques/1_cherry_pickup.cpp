#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[1010][1010];

int dx[] = {1, 0};
int dy[] = {0, 1};

int dp[101][101][101];

bool check(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

int rec(int i, int j, int a){
    int b = i+j-a; // b can be dropped from parameters as it is dependent on other parameters

    // pruning

    // base case
    if(i==n-1 && j==m-1){
        return arr[i][j];
    }

    // cache check
    if(dp[i][j][a]!=-1){
        return dp[i][j][a];
    }

    // transition
    int initial_cost = arr[i][j] + arr[a][b];

    if(i==a && j==b){
        initial_cost = arr[i][j];
    }
    
    int ans = 0;
    for(int k1=0;k1<2;k1++){
        for(int k2=0;k2<2;k2++){
            int na, nb, ni, nj;
            ni = i + dx[k1];
            nj = j + dy[k1];
            na = a + dx[k2];
            nb = b + dy[k2];

            if(check(ni,nj) && check(na,nb)){
                ans = max(ans, initial_cost+rec(ni,nj,na));
            }
        }
    }

    // save and return 
    return dp[i][j][a] = ans;
}

void solve(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
}

signed main(){
    solve();
    return 0;
}