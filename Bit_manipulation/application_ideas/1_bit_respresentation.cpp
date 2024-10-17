#include<bits/stdc++.h>
using namespace std;

void print(int n){
    vector<int> arr;
    while(n>0){
        arr.push_back((n&1));
        n = n>>1;
    }

    reverse(arr.begin(), arr.end());
    for(auto v: arr){
        cout<<v;
    }

    cout<<endl;
}

void solve(){
    int n;
    cin>>n;

    print(n);
}

signed main(){
    solve();
    return 0;
}