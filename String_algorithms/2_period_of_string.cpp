#include<bits/stdc++.h>
using namespace std;

void kmp(string s, vector<int>& arr){
    int i = 0;
    int j = -1;

    int n = s.length();

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

void periodOfString(string s){
    int n = s.size();

    vector<int> arr(n+1,0);

    arr.clear();
    arr.resize(n+1);
    kmp(s,arr);

    int period = n - arr[n];
    if(n%period==0 && period>=1 && period!=n){
        cout<<n<<" "<<n/period<<endl;
    }
    return;
}

void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(int i=1;i<=n;i++){
        string str = s.substr(0,i);
        periodOfString(str);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    int i = 1;
    while(i<=T){
        cout<<"Test case #"<<i<<endl;
        solve();
        cout<<endl;
        i++;
    }
    return 0;
}