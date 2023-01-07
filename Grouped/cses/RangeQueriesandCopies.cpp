#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int TSZ=1<<20;
ll tree[TSZ*2], kAt[TSZ], ans[TSZ];
bool vis[TSZ];
vector<int> qs[TSZ], gr[TSZ];

ll merge(ll a, ll b) {
	return a+b;
}

ll query(int node, int segL, int segR, int l, int r) {
	if (r<=segL || l>=segR) return 0;
	if (l<=segL && segR<=r) return tree[node];
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, l, r), query(node*2+1, mid, segR, l, r));
}

ll upt(int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) return tree[node]=val;
	int mid=segL+segR>>1;
	return tree[node]=merge(upt(node*2, segL, mid, pos, val), upt(node*2+1, mid, segR, pos, val));
}

void dfs(int q) {
	int a=qs[q][0], b=qs[q][1], c=qs[q][2], d=qs[q][3], past=tree[TSZ+c];
	
	if (a==1) upt(1,0,TSZ,c,d);
	else if (a==2) ans[q]=query(1,0,TSZ,c,d);

	for (int i : gr[q]) {
		if (vis[i]) continue;
		vis[i]=1;
		dfs(i);
	}
	if (a==1) upt(1,0,TSZ,c,past);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(tree,0);
	ms(kAt,0);
	ms(vis,0);

	int N,Q; cin>>N>>Q;
	for (int i=0; i<N; i++)	cin>>tree[i+TSZ];
	for (int i=TSZ-1; i; i--) tree[i]=merge(tree[i<<1], tree[i<<1|1]);

	int numOfAr=1;
	for (int i=0; i<Q; i++) {
		vector<int> v(4);
		cin>>v[0]>>v[1];
		if (v[0]!=3) cin>>v[2]>>v[3], v[2]--;
		qs[i]=v;

		// dealing with array k: connect to query i
		gr[kAt[v[1]]].push_back(i);

		// if creating new array copy of k, set the kAt of this new array to this query
		// otherwise if modifying/summing array k, set latest kAt to this query i.
		if (v[0]==3) kAt[++numOfAr]=i;
		else kAt[v[1]]=i;
	}

	vis[0]=1;
	dfs(0);

	for (int i=0; i<Q; i++) if (qs[i][0]==2) cout << ans[i] << endl;
}