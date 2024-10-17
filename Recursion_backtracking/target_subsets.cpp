#include<bits/stdc++.h>
using namespace std;

int n,x;
int arr[1001001];
int sum;

int rec(int level, int ind){
    if(level<=n){
        return 1;
    }
    if(ind>n){
        return 0;
    }

    int ans = 0;
    ans += rec(level,ind+1);
    ans += rec(level+arr[ind],ind+1);

    return ans;
}

void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<rec(0,0);    
}

int main(){
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}