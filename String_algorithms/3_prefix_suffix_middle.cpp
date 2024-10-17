#include<bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> arr;

void kmp(){
    int i=0, j=-1;
    arr[0] = -1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j = arr[j];
        }
        i++;
        j++;
        arr[i] = j;
    }
}   

void solve(){
    cin>>n;
    cin>>s;

    arr.assign(n+1,0);
    kmp();

    int a = arr[n];
    int b = arr[2];
    for(int i=3;i<n;i++){
        b = max(b, arr[i]);
    }

    int len = min(a,b);
    // cout<<"a: "<<a<<" b: "<<b<<endl;

    if(len==0){
        cout<<-1<<endl;
    }else{
        string ans;
        for(int i=0;i<len;i++){
            ans.push_back(s[i]);
        }

        cout<<ans<<endl;
    }

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