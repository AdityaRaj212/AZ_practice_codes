#include<bits/stdc++.h>
using namespace std;

void solve(){
    bitset<8> x("1010");
    bitset<8> y("1100");

    cout<<"x = 1010"<<endl;
    cout<<"y = 1100"<<endl<<endl;

    cout<<"x&y = "<<(x&y)<<endl;
    cout<<"x|y = "<<(x|y)<<endl;
}

signed main(){
    solve();
    return 0;
}