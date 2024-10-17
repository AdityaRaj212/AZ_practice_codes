#include<bits/stdc++.h>
#define inf 1e9
#define endl "\n"
#define int long long

using namespace std;

int n;
vector<int> x;
vector<int> y;
int dp[101][101];
int back[101][101];
int opb[101];
int clb[101];

int rec(int l, int r){
    // pruning
    if(l>r){
        return 0;
    }

    // base case
    if(l==r){
        return 0;
    }

    // cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    // transition
    int ans = inf;
    for(int mid=l;mid<r;mid++){
        if(rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r]<ans){
            ans = rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r];
            back[l][r] = mid;
        }
    }

    // save and return 
    return dp[l][r] = ans;
}

void generate(int l, int r){
    if(l==r){
        return;
    }
    opb[l]++;
    clb[r]++;
    int mid = back[l][r];
    generate(l,mid);
    generate(mid+1,r);
}

void solve(){   
    cin>>n;
    x.resize(n);
    y.resize(n);

    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
    generate(0,n-1);

    for(int i=0;i<n;i++){
        for(int x=0;x<opb[i];x++){
            cout<<"(";
        }
        cout<<i;
        for(int x=0;x<clb[i];x++){
            cout<<")";
        }
    }
}

signed main(){
    solve();
    return 0;
}