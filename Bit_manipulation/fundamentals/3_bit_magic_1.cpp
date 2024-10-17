#include<bits/stdc++.h>
#define int long long

using namespace std;

int test(int n, int i){
    return ((n>>i)&1);
}

int set_(int n, int i){
    n = n | (1LL<<i);
    return n;
}

int clear(int n, int i){
    n = n & (~(1LL<<i));
    return n;
}

int flip(int n, int i){
    n = n ^ (1LL<<i);
    return n;
}

int all(int n){
    for(int i=0;i<60;i++){
        if(((n>>i)&1)==0){
            return 0;
        }
    }
    return 1;
}

int any_(int n){
    for(int i=0;i<60;i++){
        if(((n>>i)&1)==1){
            return 1;
        }
    }
    return 0;
}

int none(int n){
    return !(any_(n));
}

int count(int n){
    int ans = 0;
    for(int i=0;i<60;i++){
        if((n>>i)&1){
            ans++;
        }
    }
    return ans;
}

int val(int n){
    return n;
}

void solve(){
    int n = 0;

    int q;
    cin>>q;
    
    while(q--){
        int query;
        cin>>query;

        switch (query)
        {
        case 1:{
            int i;
            cin>>i;
            cout<<test(n,i)<<endl;
            break;
        }
        
        case 2:{
            int i;
            cin>>i;
            n = set_(n,i);
            break;
        }

        case 3:{
            int i;
            cin>>i;
            n = clear(n,i);
            break;
        }

        case 4:{
            int i;
            cin>>i;
            n = flip(n, i);
            break;
        }

        case 5:{
            cout<<all(n)<<endl;
            break;
        }

        case 6:{
            cout<<any_(n)<<endl;
            break;
        } 

        case 7:{
            cout<<none(n)<<endl;
            break;
        }

        case 8:{
            cout<<count(n)<<endl;
            break;
        }

        case 9:{
            cout<<val(n)<<endl;
            break;
        }
        
        default:
            break;
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    solve();
    return 0;
}
