#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int N,M,md=1000000;
vector<vector<ll>> G;
vector<int> isC;
vector<vector<int>> from;

vector<bool> done;
ll go(vector<ll> &H, int at, int cnt) {
	if (done[at]) return H[at];
	for (int par : from[at]) H[at]+=go(H, par, cnt), H[at]%=md;
	done[at]=1;
	return H[at];
}

void SP(vector<ll> &D, vector<ll> &H, int start, bool f) {
	from.assign(N,{});
	vector<bool> vis(N);
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
	pq.push({0, start, 0, start}); // dis, node, cookie count, from
	D[start]=0;
	
	while (!pq.empty()) {
		vector<ll> node=pq.top(); pq.pop();
		if (node[0]==D[node[1]]) from[node[1]].push_back(node[3]); 
		if (vis[node[1]]) continue;
		vis[node[1]]=1;

		if (!f && node[2]==1) continue;

		for (int child=0; child<N; child++) {
			if (!vis[child]) {
				ll nDis=node[0]+G[node[1]][child], cCnt=node[2]+isC[child];
				if (nDis<=D[child] && (f || cCnt<=1)) 
					pq.push({nDis,child,cCnt,node[1]}), 
					D[child]=nDis;
			}
		}
	}

	done.assign(N,0), done[start]=1, H[start]=1;
	for (int i=0; i<N; i++) {
		if (!done[i]) go(H,i,1);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	G.assign(N, vector<ll>(N));
	for (int a=0; a<N; a++) for (int b=0; b<N; b++) cin>>G[a][b];
	
	cin>>M;
	vector<int> C(M); isC.assign(N,0);
	for (int i=0; i<M; i++) cin>>C[i], --C[i], isC[C[i]]=1;

	vector<ll> H1(N), H2(N), D1(N,LLONG_MAX), D2(N,LLONG_MAX);
	SP(D1,H1,0,1), SP(D2,H2,N-1,0);

	ll a=LLONG_MAX, b=0;
	for (int i : C) if (D1[i]!=LLONG_MAX && D2[i]!=LLONG_MAX) a=min(a, D1[i]+D2[i]);
	for (int i : C) if (D1[i]+D2[i]==a) b+=H1[i]*H2[i], b%=md;
	cout << a << ' ' << b << endl;
}