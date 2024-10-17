#include <bits/stdc++.h>
#define inf 1e9
#define endl "\n" 

using namespace std;

int n,m;
int dp[1010][1010];
int back[1010][1010];
string result;

int rec(int i, int j, string a, string b){
    // cout<<"entering rec"<<endl;
    // pruning

    // base case
    if(i==n && j==m){
        return 0;
    }

    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // transition
    int ans = inf;
    if(i<n){
        if (1 + rec(i + 1, j, a, b) < ans) { // option 1
            ans = 1 + rec(i + 1, j, a, b);
            back[i][j] = 1;
        }
    }
    if(j<m){
        if(1+rec(i,j+1,a,b)<ans){ // option 2
            ans = 1+rec(i,j+1,a,b);
            back[i][j] =2;
        }
    }
        
    if(i<n && j<m && a[i]==b[j]){  
        if(1+rec(i+1,j+1,a,b)<ans){ // option 3
            ans = 1+rec(i+1,j+1,a,b);
            back[i][j] = 3;
        }
    }
    

    // save and return
    return dp[i][j] = ans;
}

void generate(int i, int j, string a, string b,string ans){
    // cout<<"entering generate"<<endl;
    if(i==n && j==m){
        return ;
    }

    int ch = back[i][j];

    if(ch==1){
        // cout<<a[i];
        result.push_back(a[i]);
        generate(i+1,j,a,b,ans);
    }else if(ch==2){
        // cout<<b[j];
        result.push_back(b[j]);
        generate(i,j+1,a,b,ans);
    }else{
        // cout<<a[i];
        result.push_back(a[i]);
        generate(i+1,j+1,a,b,ans);
    }
}

string shortestSupersequence(string a, string b)
{
	// Write your code here.
    // cout<<"entering shortest.."<<endl;
    n = a.size();
    m = b.size();

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = -1;
        }
    }

    rec(0,0,a,b);
    string ans;
    generate(0,0,a,b,ans);

    ans = result;
    result.clear();

    return ans;
}

void solve(){
    string a,b;
    cin>>a>>b;

    cout<<shortestSupersequence(a,b)<<endl;
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