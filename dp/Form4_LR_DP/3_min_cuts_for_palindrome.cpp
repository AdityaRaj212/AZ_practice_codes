#include<bits/stdc++.h>
#define inf 1e9
#define endl "\n"
#define int long long

using namespace std;

string s;
int n;
int dp1[1001][1001];
int dp2[1001];

int rec1(int l, int r){ // whether [l...r] is a palindrome or not
    if(l>=r){
        return 1;
    }
    if(dp1[l][r]!=-1){
        return dp1[l][r];
    }
    int ans = 0;
    if(s[l]==s[r] && rec1(l+1,r-1)){
        ans = 1;
    }

    return dp1[l][r] = ans;
}

int rec2(int i){ // min no of cuts from [0....i]
    if(i<0){
        return -1;
    }

    if(dp2[i]!=-1){
        return dp2[i];
    }

    int ans = inf;
    for(int j=0;j<i;j++){
        if(rec1(j+1,i)){
            ans = min(ans,1+rec2(j));
        }
    }

    return dp2[i] = ans;
}

void solve(){
    cin>>s;
    n = s.size();

    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));

    cout<<rec2(n)<<endl;
}

signed main(){
    solve();
    return 0;
}