#include<bits/stdc++.h>

using namespace std;
using lli = long long;

struct hasher{
    int size;
    lli p, mod;
    vector<int> fHash;
    vector<int> pk;

    void init(string s, int _p, int _mod){
        size = s.length();
        p = _p;
        mod = _mod;

        fHash.resize(size);
        pk.resize(size);

        fHash[0] = s[0]-'a'+1;
        pk[0] = 1;

        for(int i=1;i<size;i++){
            fHash[i] = (fHash[i-1]*p + s[i]-'a'+1)%mod;
            pk[i] = (pk[i-1]*p)%mod;
        }
    }

    lli getfHash(int l, int r){
        if(l==0){
            return fHash[r];
        }else{
            return ((fHash[r]-fHash[l-1]*pk[r-l+1])%mod + mod)%mod;
        }
    }
};

int n;
string s;
hasher shash;

bool comp(int i, int j){
    int lo = 1;
    int hi = n;
    int ans = 0;

    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(shash.getfHash(i, i+mid-1)==shash.getfHash(j, j+mid-1)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }

    if(ans==n){
        return 0;
    }else{
        return s[i+ans]<s[j+ans];
    }
}

void solve(){
    cin>>s;
    n = s.length();
    s = s + s;

    shash.init(s, 37, 999999937);
    vector<int> final;

    for(int i=0;i<n;i++){
        final.push_back(i);
    }

    sort(final.begin(), final.end(), comp);
    for(auto v: final){
        cout<<v<<" ";
    }
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}