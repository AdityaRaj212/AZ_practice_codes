#include<bits/stdc++.h>
using namespace std;

vector<int> pteam;
vector<int> team_size;
vector<int> team_par;

int find_root(int team){
    if(team_par[team]==team){
        return team;
    }
    team_par[team] = find_root(team_par[team]);
    return team_par[team];
}

void merge(int a, int b){
    int ra = find_root(a);
    int rb = find_root(b);

    if(ra==rb) return;
    team_par[ra] = rb;
    team_size[rb]+=team_size[ra];
}

void solve(){
    int n,m;
    cin>>n>>m;

    pteam.assign(n+1,-1);
    team_size.assign(m+1,0);
    team_par.resize(m+1);

    for(int i=1;i<=m;i++){
        team_par[i] = i;
    }

    int q;
    cin>>q;

    while(q--){
        if(q==1){
            int x,a;
            cin>>x>>a;
            if(pteam[x]!=-1){
                int xteam = find_root(pteam[x]);
                team_size[xteam]--;
            }
            pteam[x] = a;
            int xteam = find_root(pteam[x]);
            team_size[xteam]++;
        }
        else if(q==2){
            int a,b;
            cin>>a>>b;
            merge(a,b);
        }
        else if(q==3){
            int x,y;
            cin>>x>>y;

            int xteam = pteam[x];
            int yteam = pteam[y];

            if(xteam==-1 || yteam==-1){
                cout<<"No"<<endl;
            }
            else{
                int rx = team_par[xteam];
                int ry = team_par[yteam];

                if(rx==ry){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
        }
        else if(q==4){
            int x;
            cin>>x;

            if(pteam[x] == -1){
                cout<<0<<endl;
            }
            else{
                cout<<team_size[pteam[x]]<<endl;
            }
        }
    }
}

int main(){
    solve();
    return 0;
}