
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define inf 1e9
using namespace std;
using state = pair<int,int>;

vector<vector<int>> board;
vector<vector<int>> vis;
vector<vector<int>> dis;

bool is_valid(int row, int col,int n){
	if(row>0 && row<=n && col>0 && col<=n){
		return true;
	}
	return false;
}

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

vector<state> neighbours(int row, int col, int n){
	vector<state> neighs;
	for(int i=0;i<8;i++){
		if(is_valid(row+dy[i],col+dx[i],n)){
			neighs.push_back(MP(row+dy[i],col+dx[i]));
		}
	}
	return neighs;
}

void bfs(state node, int n){
	vis[node.F][node.S] = 1;
	queue<state> q;
	q.push(node);
	dis[node.F][node.S] = 0;

	while(!q.empty()){
		state curr = q.front();
		q.pop();

		for(auto v:neighbours(curr.F,curr.S,n)){
			if(!vis[v.F][v.S]){
				vis[v.F][v.S] = 1;
				dis[v.F][v.S] = dis[curr.F][curr.S]+1;
				q.push(v);
			}
		}
	}
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
	// Complete the function
    int n = N;
	vis.assign(n+1,vector<int>(n+1,0));
	dis.assign(n+1,vector<int>(n+1,inf));
	bfs(MP(Sx,Sy),n);
	if(dis[Fx][Fy]==inf){
		return -1;
	}
	else{
		return dis[Fx][Fy];
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
