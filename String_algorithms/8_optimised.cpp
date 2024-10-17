#include<bits/stdc++.h>

using namespace std;
using lli = long long;

struct hasher{
    int n;
    lli p, mod;
    vector<int> fHash, rHash, pk;

    void init(string s, lli _p, lli _mod){
        n = s.size();
        p = _p;
        mod = _mod;

        // forward hash
        fHash.resize(n);
        pk.resize(n);

        fHash[0] = s[0]-'a'+1;
        pk[0] = 1;

        for(int i=1;i<n;i++){
            fHash[i] = (1LL*fHash[i-1]*p + s[i]-'a'+1)%mod;
            pk[i] = (1LL*pk[i-1]*p)%mod;
        }

        // reverse hash
        rHash.resize(n+1);
        rHash[n] = 0;
        for(int i=n-1;i>=0;i--){
            rHash[i] = (1LL*rHash[i+1]*p + s[i]-'a'+1);
        }
    }

    int getfHash(int l, int r){
        if(l==0){
            return fHash[r];
        }else{
            return ((fHash[r]-(1LL*fHash[l-1]*pk[r-l+1])%mod)+mod)%mod;
        }
    }

    int getrHash(int l, int r){
        return ((rHash[l]-(1LL*rHash[r+1]*pk[r-l+1])%mod)+mod)%mod;
    }
};

struct double_hash{
    hasher a,b;

    void init(string s){
        a.init(s, 31, 1000000009);
        b.init(s, 37, 1000000021);
    }

    pair<int,int> getfHash(int l, int r){
        return {a.getfHash(l,r), b.getfHash(l,r)};
    }

    pair<int,int> getrHash(int l, int r){
        return {a.getrHash(l,r), b.getrHash(l,r)};
    }
};

int n;
double_hash hs;
unordered_set<lli>  seen;

bool isSame(int len){
    for(int i=0;i+len<n;i++){
        auto hash = hs.getfHash(i,i+len).first;
        if(seen.find(hash)!=seen.end()){
            return true;
        }
        seen.insert(hash);
    }
    return false;
}

string longestDupSubstr(string s){
    n = s.size();
    
    hs.init(s);

    int lo = 1;
    int hi = n-1;
    int best_len = 0;

    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(isSame(mid)){
            best_len = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    string ans;

    if(best_len==0){
        ans = "";
    }else{
        for(int i=0;i+best_len<n;i++){
            auto hash = hs.getfHash(i,i+best_len).first;
            if(seen.find(hash)!=seen.end()){
                ans = s.substr(i,best_len);
            }
        }
    }
    return ans;
}

void solve(){

}

signed main(){
    solve();
    return 0;
}