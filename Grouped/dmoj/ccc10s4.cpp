#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))


const int MAXN=1001;
pair<int,int> found[MAXN][MAXN]; // first=cost, second=pen
int E[MAXN], C[MAXN], dsu[MAXN];
vector<vector<int>> edges, look;

int hit=0;


int root(int a) {
	return dsu[a]<0 ? a : dsu[a]=root(dsu[a]);
}

bool unite(int a, int b) {
	a=root(a), b=root(b);
	if (a==b) return 0;
	if (dsu[a]>dsu[b]) swap(a,b);
	dsu[a]+=dsu[b];
	dsu[b]=a;
	return 1;
}


int mst(int x) {
	fill(dsu,dsu+MAXN,-1);
	sort(edges.begin(), edges.end());

	int ans=0;
	for (vector<int> e : edges) {
		if (unite(e[1], e[2])) {
			ans+=e[0];
			if (x) hit++;
		}
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(found,0);
	
	int M; cin>>M;
	for (int p=1; p<=M; p++) {
		int e; cin>>e;
		for (int i=0; i<e; i++) cin>>E[i];
		for (int i=0; i<e; i++) cin>>C[i];

		for (int i=0; i<e; i++) {
			int a=E[i], b=E[(i+1)%e];
			if (a>b) swap(a,b);
			if (found[a][b].second) 
				edges.push_back({C[i], found[a][b].second, p}),
				found[a][b].second=0;
			else found[a][b]=make_pair(C[i], p), look.push_back({a,b});
		}
	}
	int ans=mst(1);
	for (vector<int> l : look) {
		int a=l[0], b=l[1];
		if (found[a][b].second) 
			edges.push_back({found[a][b].first, found[a][b].second, 0});
	}
	
	int nw=mst(0);
	if (hit==M-1) {
		ans=min(ans, nw);
	}
	else ans=nw;
	cout << ans << endl;

}

/*
4
3 1 2 3 2 6 4
4 2 4 5 3 2 4 3 6
3 3 5 7 3 5 5
3 3 7 6 5 4 4
*/