    #include<bits/stdc++.h>
    #define MP make_pair
    #define F first 
    #define S second 
    #define inf 1e18
    #define int long long

    using namespace std;

    int n,m;
    vector<vector<pair<int,int>>> g;
    vector<int> dis;
    vector<pair<pair<int,int>,int>> edges;

    void dijkstra(int sc_node){
        priority_queue<pair<int,int>> pq;
        pq.push(MP(-0,sc_node));
        dis[sc_node] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int node = curr.S;

            for(auto v:g[node]){
                int next_node = v.F;
                int cost = v.S;
                if(dis[next_node]>dis[node]+cost){
                    dis[next_node]=dis[node]+cost;
                    pq.push(MP(-dis[next_node],next_node));
                }
            }
        }
    }

    void solve(){
        cin>>n>>m;
        g.resize(n+1);

        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back(MP(b,c));
            g[b].push_back(MP(a,c));
            edges.push_back(MP(MP(a,b),c));
        }

        int start_node;
        cin>>start_node;
        dis.assign(n+1,inf);
        dijkstra(start_node);

        int ans = -inf;

        for(auto it:edges){
            int u = it.F.F;
            int v = it.F.S;
            int cost = it.S;

            ans = max(ans,(dis[u]+dis[v]+cost)*5);
        }

        cout<<ans<<"\n";
    }

    signed main(){
        solve();
        return 0;
    }