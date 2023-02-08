#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=2e5+1, E=31;
int path[MAXN], node2flat[MAXN], nwNode[MAXN], nodeSz[MAXN], ans[MAXN], ord[MAXN];
vector<int> qs[MAXN], tr[MAXN], binTr[MAXN][2];
multiset<vector<int>> paths;

int cnt=1;
int rec(int node) {
	nodeSz[node]=1;
	node2flat[node]=cnt++;
	for (int child : tr[node]) {
		nodeSz[node]+=rec(child);
	}
	return nodeSz[node];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(path,0);
	int Q; cin>>Q;
	int sz=1;
	for (int q=0; q<Q; q++) {
		string s; int a,b; cin>>s>>a>>b;
		qs[q]={s=="Add", a, b};

		if (qs[q][0]) {
			path[++sz]=path[qs[q][1]]^qs[q][2];
			tr[qs[q][1]].push_back(sz);
			nwNode[q]=sz;
		}
	}

	rec(1);

	// create bin tree
	for (int node=1; node<=sz; node++) {
		int at=0;
		for (int e=E-1; e>=0; e--) {
			binTr[node][node>>e&1]=++at;
		}
	}
}
/*
13
Add 1 2
Add 1 5
Add 3 32
Add 3 7
Add 2 8
Add 5 1
Query 1 1
Query 2 1
Query 3 1
Query 4 1
Query 5 1
Query 6 1
Query 7 1

Correct:
12
15
14
15
14
15
15

Incorrect:
19
23
22
31
17
31
24

*/