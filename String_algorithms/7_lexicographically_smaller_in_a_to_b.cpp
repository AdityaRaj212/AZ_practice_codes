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
        pk.resize(n+1);
        fHash[0] = s[0]-'a'+1;
        pk[0] = 1;

        for(int i=1;i<n;i++){
            fHash[i] = ((1LL * fHash[i-1] * p)+(s[i]-'a'+1))%mod;
            pk[i] = pk[i-1]*p;
        }

        // reverse hash
        rHash.resize(n+1);
        rHash[n] = 0;
        rHash[n-1] = s[n-1]-'a'+1;
        
        for(int i=n-2;i>=0;i--){
            rHash[i] = ((1LL * rHash[i+1] * p)+(s[i]-'a'+1))%mod;
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
    hasher a, b;
    string temp;

    void init(string s){
        temp = s;
        a.init(s, 31, 1000000009);
        b.init(s, 37, 1000000021);
    }

    pair<int,int> getfHash(int l, int r){
        return {a.getfHash(l,r), b.getfHash(l,r)};
    }

    pair<int,int> getrHash(int l, int r){
        return {a.getrHash(l,r),b.getrHash(l,r)};
    }

    int lex_order(int i, int j, int len){
        int ans = 0;
        int lo = 1;
        int hi = len;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(getfHash(i, i+mid-1)==getfHash(j,j+mid-1)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        if(ans==len){
            return 0;
        }else{
            if(temp[i+ans]<temp[j+ans]){
                return -1;
            }else{
                return 1;
            } 
        }
    }
};

int n;
string s;
double_hash hs;

bool cmp(int i, int j){
    int len = n-max(i,j);
    int oval = hs.lex_order(i,j,len);
    if(oval==0){
        if(i>j){
            return true;
        }else{
            return false;
        }
    }else{
        if(oval<0){
            return true;
        }else{
            return false;
        }
    }
}

void solve(){
    cin>>s;
    n = s.size();

    hs.init(s);

    int q;
    cin>>q;

    while(q--){
        int l,r,x;
        cin>>l>>r>>x;

        cout<<hs.lex_order(l,r,x)<<endl;
    }
}

signed main(){
    solve();
    return 0;
}