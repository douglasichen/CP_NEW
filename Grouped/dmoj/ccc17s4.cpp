#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e5+1, MAXM=2e5;
int edges[MAXM][3], order[MAXM], used[MAXM], used2[MAXM], dsu[MAXN], fromCost[MAXN], from[MAXN];
bool vis[MAXN];
vector<vector<int>> G[MAXN];

int root(int a) {
	return (dsu[a]<0 ? a : dsu[a]=root(dsu[a]));
}

bool unify(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return 0;
	if (dsu[a]>dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b]=a;
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	fill(dsu,dsu+MAXN,-1);
	ms(used,0);
	ms(used2,0);

	int N,M,D; cin>>N>>M>>D;
	for (int i=0; i<M; i++) {
		cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
		if (i<N-1) used[i]=1;
	}
	iota(order,order+M,0);
	sort(order,order+M,[&](int a, int b){
		if (edges[a][2]==edges[b][2]) return used[a]>used[b];
		return edges[a][2]<edges[b][2];
	});
	for (int i=0; i<M; i++) {
		int ind=order[i];
		if (unify(edges[ind][0], edges[ind][1])) {
			G[edges[ind][0]].push_back({edges[ind][2], edges[ind][1]});
			G[edges[ind][1]].push_back({edges[ind][2], edges[ind][0]});
			used2[ind]=1;
		}
	}

    // D!=0
	ll mstCost=0, mnCost;
	for (int i=0; i<M; i++)
		if (used2[i])
			mstCost+=edges[i][2];
	
	mnCost=mstCost;
	for (int i=0; i<M; i++)
		if (used2[i])
			mnCost=min(mnCost, mstCost-(edges[i][2]-max(0,edges[i][2]-D)));

	// create fromCost
	int start=1;
	for (int i=1; i<=N; i++) {
		if (SZ(G[i])<=1) {
			start=i;
			break;
		}
	}
	if (SZ(G[start])) fromCost[start]=G[start][0][0], from[start]=G[start][0][1];

	// dfs to build fromCost
	ms(vis,0);
    ms(from,0);
    ms(fromCost,0);
	vis[start]=1;
	stack<int> st; st.push(start);
	while (SZ(st)) {
		int node=st.top(); st.pop();
		for (vector<int> child : G[node]) {
			if (!vis[child[1]]) {
				vis[child[1]]=1;
				fromCost[child[1]]=child[0];
				from[child[1]]=node;
				st.push(child[1]);
			}
		}
	}

	int best=-1;
	ll newMstCost;
	for (int i=0; i<M; i++) {
		if (!used2[i]) {
			vector<int> e={edges[i][0], edges[i][1], edges[i][2]};
			newMstCost=mstCost+max(0,e[2]-D) - max(fromCost[e[0]], fromCost[e[1]]);
			// if (newMstCost<mnCost) {
			// 	mnCost=newMstCost;
			// 	best=i;
			// }
		}
	}


	if (best!=-1) {
		vector<int> e={edges[best][0], edges[best][1]};

		int a=e[0], b=from[e[0]];
		for (int i=0; i<M; i++) 
			if (edges[i][0]==a && edges[i][1]==b || edges[i][1]==a && edges[i][0]==b)
				used2[i]=0;

		a=e[1], b=from[e[1]];
		for (int i=0; i<M; i++) 
			if (edges[i][0]==a && edges[i][1]==b || edges[i][1]==a && edges[i][0]==b)
				used2[i]=0;
		
		used2[best]=1;
	}  

	for (int i=0; i<M; i++) used[i]^=used2[i];
	cout << (accumulate(used,used+M,0)+1)/2 << endl;
}