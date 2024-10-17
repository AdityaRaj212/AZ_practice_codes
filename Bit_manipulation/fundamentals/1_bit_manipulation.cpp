#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int mask=0; mask<(1<<n); mask++){
        cout<<mask<<": ";
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                cout<<arr[i]<<", ";
            }
        }
        cout<<endl;
    }
}

signed main(){
    solve();
    return 0;
}