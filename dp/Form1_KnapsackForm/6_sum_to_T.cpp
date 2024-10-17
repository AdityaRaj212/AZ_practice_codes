#include<bits/stdc++.h>
using namespace std;

int n, T, q;
vector<int> arr;
int dp[1001][1001];

int rec(int level, int left){
    //pruning
    if(left<0){
        return 0;
    }

    // base case
    if(level==n){
        if(left==0){
            return 1;
        }else{
            return 0;
        }
    }

    // cache check
    if(dp[level][left]!=-1){
        return dp[level][left];
    }

    // transition
    int ans = 0;
    if(rec(level+1,left)==1){
        ans = 1;
    }else if(rec(level+1,left-arr[level])==1){
        ans = 1;
    }

    // save and return 
    return dp[level][left] = ans;
}

void printset(int level, int left){
    // base case
    if(level==n){
        return;
    }

    if(rec(level+1,left)==1){
        printset(level+1,left);
    }else if(rec(level+1,left-arr[level])==1){
        cout<<arr[level]<<' ';
        printset(level+1,left-arr[level]);
    }
}

void solve(){
    cin>>n>>q;

    arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp,-1,sizeof(dp));

    while(q--){
        cin>>T;
        if(rec(0,T)){
            printset(0,T);
            cout<<endl;
        }else{
            cout<<"Not possible"<<endl;
        }

    }
}

signed main(){
    solve();
    return 0;
}