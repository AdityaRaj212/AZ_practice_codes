#include<bits/stdc++.h>
#define endl "\n"
#define int long long 

using namespace std;

set<int> s;
int q;

void solve(){
    cin>>q;

    for(int i=0;i<q;i++){
        string op;
        cin>>op;

        int x;
        cin>>x;

        if(op=="add"){
            s.insert(x);
        }else if(op=="remove"){
            s.erase(x);
        }else if(op=="find"){
            auto it = s.begin();
            int count = 0;
            if(x<s.size()){
                while(count<x){
                    count++;
                    it++;
                }
                cout<<*it<<endl;
            }else{
                cout<<-1<<endl;
            }
        }else if(op=="findpos"){
            auto it = s.begin();
            int count = 0;
            while(it!=s.end()){
                if(*it==x || *it>x){
                    break;
                }
                it++;
                count++;
            }
            cout<<count<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    while(T--){
        s.clear();
        solve();
    }

    return 0;
}