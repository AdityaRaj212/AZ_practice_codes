#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
int n;

int oddOne(){
    int ans = 0;
    for(auto v:arr){
        ans = ans^v;
    }
    return ans;
}

void solve(){
    cin>>n;
    arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<oddOne()<<endl;
}

signed main(){
    solve();
    return 0;
}