#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=2e5+1, E=31;
int path[MAXN], node2flat[MAXN], nwNode[MAXN], nodeSz[MAXN], ans[MAXN];
vector<int> qs[MAXN], tr[MAXN];

struct Node {
	set<int> v;
	int left=0, right=0;
};

int binSz=1;
Node bin[MAXN*E+1];

// build binary tree
void build(int pos, int id, int l) {
	if (l<0) return;
	int pathVal=path[id], flatPos=node2flat[id];
	binSz++;

	if (pathVal>>l&1) {
		if (!bin[pos].right) bin[pos].right=binSz;
		int right=bin[pos].right;
		bin[right].v.insert(flatPos);
		build(right, id, l-1);
	}
	else {
		if (!bin[pos].left) bin[pos].left=binSz;
		int left=bin[pos].left;
		bin[left].v.insert(flatPos);
		build(left, id, l-1);
	}
}

// remove nodes
void rem(int pos, int id, int l) {
	if (l<0) return;
	int pathVal=path[id], flatPos=node2flat[id];
	if (pathVal>>l&1) {
		int right=bin[pos].right;
		bin[right].v.erase(flatPos);
		rem(right, id, l-1);
	}
	else {
		int left=bin[pos].left;
		bin[left].v.erase(flatPos);
		rem(left, id, l-1);
	}
}

// calculate size of sub trees and node2flat conversion
int cnt=0;
int rec(int node) {
	nodeSz[node]=1;
	node2flat[node]=++cnt;
	for (int child : tr[node]) nodeSz[node]+=rec(child);
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

	// build bin tree
	for (int i=1; i<=sz; i++) {
		build(1,i,30);
	}
	
	// answer queries backwards
	for (int q=Q-1; q>=0; q--) {
		if (qs[q][0]) rem(1, nwNode[q], 30);
		else {
			int pathVal=path[qs[q][1]], flatPos=node2flat[qs[q][2]];
			for (int e=E-1; e>=0; e--) {
				if (pathVal>>e&1) pathVal-=1<<e;
				else pathVal+=1<<e;
			}
		
			int L=flatPos, R=flatPos+nodeSz[qs[q][2]], at=1;
			for (int e=E-1; e>=0; e--) {
				bool rGd=0, lGd=0;
				int right=bin[at].right, left=bin[at].left;
				if (pathVal>>e&1) {
					if (right) {
						auto itR=bin[right].v.lower_bound(L);
						rGd=(itR!=bin[right].v.end()) && *itR<R;
					}
					if (!rGd) pathVal-=1<<e;
				}
				else {
					if (left) {
						auto itL=bin[left].v.lower_bound(L);
						lGd=(itL!=(bin[left].v.end())) && *itL<R;
					}
					if (!lGd) pathVal+=1<<e;
				}
				if (pathVal>>e&1) at=right;
				else at=left;
			}
			ans[q]=(pathVal^path[qs[q][1]]);
		}
	}
	for (int q=0; q<Q; q++) {
		if (!qs[q][0]) cout << ans[q] << endl;
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
