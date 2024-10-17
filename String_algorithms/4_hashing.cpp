#include<bits/stdc++.h>

using namespace std;
using lli = long long;

lli quickHash(string s, lli p, lli mod){
    lli ans = (s[0]-'a'+1)%mod;
    for(int i=1;i<s.size();i++){
        ans = (ans*p + s[i]-'a'+1)%mod;
    }
    return ans;
}

struct hasher{
    int size;
    lli mod, p;

    vector<int> fHash;
    vector<int> pk;

    void init(string s, lli _p, lli _mod){
        p = _p;
        mod = _mod;
        size = s.length();

        fHash.resize(size);
        pk.resize(size);

        fHash[0] = s[0]-'a'+1;
        pk[0] = 1;
        for(int i=1;i<s.length();i++){
            fHash[i] = (fHash[i-1]*p + s[i]-'a'+1)%mod;
            pk[i] = (pk[i-1]*p)%mod;
        }
    }

    lli getHash(int l, int r){
        if(l==0){
            return fHash[r];
        }else{
            return ((fHash[r]-fHash[l-1]*pk[r-l+1])%mod + mod)%mod;
        }
    }
};

hasher shash;

void solve(){
    string s;
    cin>>s;

    shash.init(s, 31, 999999937);

    cout<<"Hash of "<<s<<" is: "<<shash.getHash(0,s.size()-1)<<endl;
}

signed main(){
    solve();
    return 0;
}