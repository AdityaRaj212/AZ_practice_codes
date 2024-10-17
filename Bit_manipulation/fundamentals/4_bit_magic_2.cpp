#include<bits/stdc++.h>
using namespace std;

int msb(int n){
    bitset<64> x = n;
    for(int i=0;i<64;i++){
        if(x[i]==1){
            return (63-i);
        }
    }
    return -1;
}

int rightmostSet(int n){
    bitset<64> x = n;
    for(int i=63;i>=0;i--){
        if(x[i]==1){
            return (63-i);
        }
    }
    return -1;
}

int poweroftwo(int n){
    bitset<64> x = n;
    int count = 0;
    for(int i=0;i<64;i++){
        if(x[i]==1){
            count++;
        }
    }

    return count==1;
}

int smallestPowerOfTwo(int x){
    if (x <= 1)return 2;
    return (1LL << (64 - __builtin_clzll(x - 1)));
}

void solve(){
    int n;
    cin>>n;

    bitset<64> x;
    x = n;
    
    cout<<x<<endl;
    cout<<msb(n)<<endl;
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