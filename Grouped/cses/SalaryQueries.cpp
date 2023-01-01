#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
#define ll long long
#define ALL(v) std::begin(v), std::end(v)

const int TSZ=1<<20;
int tree[TSZ*2], qs[TSZ][3], ar[TSZ];
vector<int> all;

int merge(int a, int b) {
	return a+b;
}

int incr (int node, int segL, int segR, int pos, int val) {
	if (pos<segL || pos>=segR) return tree[node];
	if (pos==segL && pos==segR-1) return tree[node]+=val;
	int mid=segL+segR>>1;
	return tree[node]=merge(incr(node*2, segL, mid, pos, val), incr(node*2+1, mid, segR, pos, val));
}


int query(int node, int segL, int segR, int L, int R) {
	if (R<=segL || L>=segR) return 0;
	if (L<=segL && segR<=R) return tree[node];
	int mid=segL+segR>>1;
	return merge(query(node*2, segL, mid, L, R), query(node*2+1, mid, segR, L, R));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(tree, 0, sizeof(tree));

	int N, Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>ar[i], all.push_back(ar[i]);

	for (int q=0; q<Q; q++) {
		char c; cin >> c >> qs[q][1] >> qs[q][2];
		qs[q][0]=(c=='?' ? 1 : 0);

		if (c=='!') all.push_back(qs[q][2]);
	}
	
	sort(ALL(all));
	all.resize(unique(ALL(all)) - all.begin());
	for (int i=0; i<N; i++) incr(1, 0, TSZ, lower_bound(ALL(all), ar[i])-all.begin(), 1);	
	
	for (int q=0; q<Q; q++) {
		int a=qs[q][0], b=qs[q][1], c=qs[q][2];
		if (a) {
			// query
			// cout << lower_bound(ALL(all), b)-all.begin() << " to " << 
				// upper_bound(ALL(all), c)-all.begin() << endl;
			cout << query(1, 0, TSZ, lower_bound(ALL(all), b)-all.begin(), 
									upper_bound(ALL(all), c)-all.begin()) << endl;
		}
		else {
			// modify
			b--;
			incr(1, 0, TSZ, lower_bound(ALL(all), ar[b])-all.begin(), -1);
			ar[b]=c;
			incr(1, 0, TSZ, lower_bound(ALL(all), ar[b])-all.begin(), 1);
		}
	}
}