#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;

    int n = s.length();
    int kmp[n+1];
    kmp[0] = -1;
    int i = 0, j = -1;

    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j = kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;
    }

    for(int i=0;i<=n;i++){
        cout<<kmp[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}