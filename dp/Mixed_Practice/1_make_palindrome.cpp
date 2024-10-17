#include<bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

string s;

void solve(){
    cin>>s;

    int lo = 0;
    int hi = s.size()-1;

    int count = 0;

    while(lo<hi){
        if(s[lo]!=s[hi]){
            count++;
            hi--;
        }else{
            hi--;
            lo++;
        }
    }

    cout<<count<<endl;
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