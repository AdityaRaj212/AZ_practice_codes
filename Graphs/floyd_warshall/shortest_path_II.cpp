#include<bits/stdc++.h>
#define inf 1e18
#define int long long
using namespace std;

int n,m,q;
vector<vector<int>> g;

void floyd_warshall(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}

void solve(){
    cin>>n>>m>>q;
    
    g.assign(n+1,vector<int>(n+1,inf));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b] = min(g[a][b],c);
        g[b][a] = min(g[b][a],c);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                g[i][j] = 0;
            }
        }
    }

    cout<<"Before:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

    floyd_warshall();  

    cout<<"After:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(g[a][b]==inf){
            cout<<-1<<"\n";
        }else{
            cout<<g[a][b]<<"\n";
        }
    }  
}

signed main(){
    solve();
    return 0;
}