#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> cnt,len;

void solve(){
    cin>>n;
    
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cnt.assign(n+1,0);
    len.assign(n+1,0);

    for(int i=1;i<=n;i++){
        
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    
    while(T--){
        solve();
    }
    
    return 0;
}