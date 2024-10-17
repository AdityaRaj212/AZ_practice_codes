#include<bits/stdc++.h>
using namespace std;

struct manacher{
    vector<int> p;

    void run_manacher(string s){
        int n = s.size();
        p.assign(n,1);
        int l = 1;
        int r = 1;

        for(int i=1;i<n;i++){
            p[i] = max(0, min(r-i, p[l+r-i]));
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
                l = i-p[i];
                r = i+p[i];
            }
        }
    }

    void build(string s){
        string t;
        for(auto v:s){
            t += (string)"#" + v;
        }
        run_manacher(t+"#");
    }

    int getLongest(int cen, bool odd){
        int pos = 2*cen + 1 + (!odd);
        return p[pos]-1;
    }
};

void solve(){
    string s;
    cin>>s;

    int maxLen = -1;
    int maxInd = -1;

    manacher m;
    m.build(s);

    for(int i=0;i<s.size();i++){
        int val = m.getLongest(i, i%2==0);
        if(val>maxLen){
            maxLen = val;
            maxInd = i;
        }
    }

    string ans;
    ans = s.substr(maxInd, maxLen);
    cout<<ans<<endl;
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