#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>s;
    n = s.size();

    vector<int> dp(n+1,0);
    vector<int> prefix(n+1,0);
    int last[26];
    memset(last,-1,sizeof(last));

    dp[0] = 1;
    prefix[0] = 1;

    for(int i=1;i<=n;i++){
        dp[i] = prefix[i-1];

        if(last[s[i-1]-'a']!=-1){
            int lastIndex = last[s[i-1]-'a'];
            dp[i] -= prefix[lastIndex];
        }

        last[s[i-1]-'a'] = i-1;
        prefix[i] = prefix[i-1] + dp[i];
    }

    cout<<prefix[n] - 1<<endl;
}

signed main(){
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    
    return 0;
}