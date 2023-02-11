#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=2e5+1, E=31;

// A
vector<vector<int>> tree[MAXN], G[MAXN];
bitset<200001> hit, vis;

// B
int path[MAXN];
vector<int> qs[MAXN];
multiset<int> paths;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(path,0);

	int Q; cin>>Q;
	for (int q=0; q<Q; q++) {
		string s; int a,b; cin>>s>>a>>b;
		qs[q]={s=="Add", a, b};
	}
	int sz=1; paths.insert(0);
	for (int q=0; q<Q; q++) {
		if (qs[q][0]) {
			path[++sz]=path[qs[q][1]]^qs[q][2];
			paths.insert(path[sz]);
		}
		else {
			int a=qs[q][1], b=qs[q][2], flip=0;

			// for (int i : paths) cout << i << ' '; cout << endl;
			// cout << path[a] << endl;

			for (int e=E-1; e>=0; e--) {
				if ((path[a]>>e&1)==0) flip+=(1<<e);

				auto it=paths.lower_bound(flip);
				if (it==paths.end() || ((*it)>>e<<e)!=flip) {
					if (flip>>e&1) flip-=(1<<e);
					else flip+=(1<<e);
				}
				// cout << "FLIP: " << flip << endl;
			}
			cout << (flip^path[a]) << endl;
		}
	}
}
/*
5
Add 1 11
Add 2 7
Add 2 11
Add 4 1
Query 3 1


Correct:
3rd: 13

Incorrect:
3rd: 15

*/