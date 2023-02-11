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
	Node *left=0, *right=0;
};

void build(Node *node, int id, int l) {
	if (l<0) return;
	int pathVal=path[id], flatPos=node2flat[id];
	if (pathVal>>l&1) {
		if (!node->right) node->right=new Node;
		node->right->v.insert(flatPos);
		build(node->right, id, l-1);
	}
	else {
		if (!node->left) node->left=new Node;
		node->left->v.insert(flatPos);
		build(node->left, id, l-1);
	}
}

ll remCnt=0;
void rem(Node *node, int id, int l) {

	remCnt++;
	if (l<0) return;
	int pathVal=path[id], flatPos=node2flat[id];
	if (pathVal>>l&1) {
		node->right->v.erase(flatPos);
		rem(node->right, id, l-1);
	}
	else {
		node->left->v.erase(flatPos);
		rem(node->left, id, l-1);
	}
}

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
	Node *root=new Node;
	for (int i=1; i<=sz; i++) build(root,i,30);
	
	// answer queries backwards
	for (int q=Q-1; q>=0; q--) {
		remCnt=0;
		if (qs[q][0]) rem(root, nwNode[q], 30), cout << remCnt << endl;
		else {
			int pathVal=path[qs[q][1]], flatPos=node2flat[qs[q][2]];
			for (int e=E-1; e>=0; e--) {
				if (pathVal>>e&1) pathVal-=1<<e;
				else pathVal+=1<<e;
			}
			
			Node *at=root;
			int L=flatPos, R=flatPos+nodeSz[qs[q][2]];
			for (int e=E-1; e>=0; e--) {
				bool rGd=0, lGd=0;
				if (pathVal>>e&1) {
					if (at->right) {
						auto itR=at->right->v.lower_bound(L);
						rGd=(itR!=(at->right->v.end())) && *itR<R;
					}
					if (!rGd) pathVal-=1<<e;
				}
				else {
					if (at->left) {
						auto itL=(at->left->v).lower_bound(L);
						lGd=(itL!=(at->left->v.end())) && *itL<R;
					}
					if (!lGd) pathVal+=1<<e;
				}
				if (pathVal>>e&1) at=at->right;
				else at=at->left;
			}
			ans[q]=(pathVal^path[qs[q][1]]);
		}
	}
	// for (int q=0; q<Q; q++) {
	// 	if (!qs[q][0]) cout << ans[q] << endl;
	// }
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

*/