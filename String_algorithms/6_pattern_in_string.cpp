#include<bits/stdc++.h>

using namespace std;
using lli = long long;

lli quickHash(string s, lli p, lli mod){
    lli ans = s[0]-'a'+1;
    for(int i=1;i<s.size();i++){
        ans = (ans*p + s[i]-'a'+1)%mod;
    }
    return ans;
}

struct hasher{
    int size;
    lli p, mod;
    vector<int> fHash, rHash;
    vector<int> pk;

    void init(string s, lli _p, lli _mod){
        int n = s.size();

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

        // reverse hash
        rHash.resize(n+1);
        rHash[n] = 0;
        for(int i=n-1;i>=0;i--){
            int val = (s[i]-'a'+1)%mod;
            rHash[i] = (rHash[i+1]*p + val)%mod;
        }
    }

    lli getfHash(int l, int r){
        if(l==0){
            return fHash[r];
        }else{
            return ((fHash[r]-fHash[l-1]*pk[r-l+1])%mod+mod)%mod;
        }
    }

    lli getrHash(int l, int r){
        if(l==0){
            return rHash[r];
        }else{
            return ((rHash[l]- 1LL * rHash[r+1]*pk[r-l+1])%mod + mod)%mod;
        }
    }
};

struct double_hash{
    hasher a,b;
    void init(string s){
        a.init(s,37,1000000021);
        b.init(s,41,1000000009);
    }

    pair<int,int> getfHash(int l, int r){
        return {a.getfHash(l,r),b.getfHash(l,r)};
    }

    pair<int,int> getrHash(int l, int r){
        return {a.getrHash(l,r),b.getrHash(l,r)};
    }

    bool isPalindrome(int l, int r){
        return getfHash(l,r)==getrHash(l,r);
    }
};


void solve(){
    // string pattern, str;
    // cin>>str>>pattern;

    // lli phash = quickHash(pattern, 31, 999999937);
    // hasher shash;
    // shash.init(str, 31, 999999937);

    // int n = str.size();
    // int m = pattern.size();

    // for(int i=0;i<n-m+1;i++){
    //     if(phash==shash.getfHash(i,i+m-1)){
    //         cout<<"Match at "<<i<<endl;     
    //     }
    // }

    string s = "abcbdabad";
    double_hash myHash;
    myHash.init(s);

    cout<<myHash.isPalindrome(1,3)<<endl;
    cout<<myHash.isPalindrome(0,4)<<endl;
}

signed main(){
    solve();
    return 0;
}