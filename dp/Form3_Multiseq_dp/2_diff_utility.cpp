#include<bits/stdc++.h>
#define inf 1e9
#define int long long

using namespace std;

int n,m;
string a,b;
int dp[1001][1001];
int back[1001][1001];

int rec(int level1, int level2){
    // pruning

    // base case
    if(level1==n && level2==m){
        return 0;
    }

    // cache check
    if(dp[level1][level2]!=-1){
        return dp[level1][level2];
    }

    // transition
    int ans = inf;

    if(level1<n){
        if(1 + rec(level1+1,level2)<ans){ // -x[l1]
            ans = 1 + rec(level1+1,level2);
            back[level1][level2] = 0;
        }
    }
    if(level2<m){
        if(1 + rec(level1,level2+1)<ans){ // +y[l2]
            ans = 1 + rec(level1,level2+1);
            back[level1][level2] = 1;
        }
    }
    if(level1<n && level2<m && a[level1]==b[level2]){
        if(1 + rec(level1+1,level2+1)<ans){ // x[l1]
            ans = 1 + rec(level1+1,level2+1);
            back[level1][level2] = 2;
        }
    }

    // save and return
    return dp[level1][level2] = ans;
}

void generate(int l1, int l2){
    if(l1==n && l2==m){
        return;
    }
    int ch = back[l1][l2];

    if(ch==0){
        cout<<"-"<<a[l1]<<" ";
        generate(l1+1,l2);
    }else if(ch==1){
        cout<<"+"<<b[l2]<<" ";
        generate(l1,l2+1);
    }else{
        cout<<a[l1]<<" ";
        generate(l1+1,l2+1);
    }
}

void solve(){
    cin>>a>>b;
    n = a.size();
    m = b.size();

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    generate(0,0);  
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}