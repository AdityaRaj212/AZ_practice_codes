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

bool isSame(int i, int j, int len){
    int rem = min(n-i, n-j);
    if(len>rem){
        return false;
    }else{
        if(hs.getfHash(i,i+len-1)==hs.getfHash(j,j+len-1)){
            return true;
        }else{
            return false;
        }
    }
}

string longestDupSubstr(string s){
    n = s.size();
    
    hs.init(s);

    int best_ind = -1;
    int best_len = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int ans = 0;
            int lo = 1;
            int hi = n-j;

            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(isSame(i,j,mid)){
                    ans = mid;
                    lo = mid+1;
                }else{
                    hi = mid-1;
                }
            }
            if(ans>best_len){
                best_len = ans;
                best_ind = i;
            }
        }
    }

    string ans = s.substr(best_ind, best_len);
    return ans;
}

void solve(){

}

signed main(){
    solve();
    return 0;
}