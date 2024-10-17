#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s;
    cin>>s;
    
    stack<char> st;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push('(');
        }
        else{
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                ans++;
            }
        }
    }
    ans += st.size();
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
    cin>>T;
    
    while(T--){
        solve();
    }
    return 0;
}