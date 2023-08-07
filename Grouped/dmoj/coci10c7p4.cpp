#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// #define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=50;
int totHit=0, ans=INT_MAX;
vector<int> post, dsu[MAXN][MAXN];;
vector<vector<int>> locs, check;
bool on[MAXN][MAXN];

vector<int> root(vector<int> a) {
	return dsu[a[1]][a[2]][0]<0 ? a : dsu[a[1]][a[2]]=root(dsu[a[1]][a[2]]);
}

void unite(vector<int> a, vector<int> b) {
	a=root(a), b=root(b);
	if (a==b) return;
	if (dsu[a[1]][a[2]][0]>dsu[b[1]][b[2]][0]) swap(a,b);
	dsu[a[1]][a[2]][0]+=dsu[b[1]][b[2]][0];
	dsu[b[1]][b[2]]=a;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			char c; cin>>c;
			if (c!='.') totHit++;
			if (c=='P') post={y,x};
			if (c=='K') check.push_back({y,x});
		}
	}
	for (int y=0; y<N; y++)
		for (int x=0,a; x<N; x++)
			cin>>a, locs.push_back({a,y,x});
	sort(locs.begin(), locs.end());
	for (int a=0; a<SZ(locs); a++) {
		for (int y=0; y<N; y++) for (int x=0; x<N; x++) dsu[y][x]={-1,0,0};
		ms(on,0);
		on[post[0]][post[1]]=1;
		for (int b=a; b<SZ(locs); b++) {
			for (int y=locs[b][1]-1; y<=locs[b][1]+1; y++) {
				for (int x=locs[b][2]-1; x<=locs[b][2]+1; x++) {
					if (y<0 || y>=N || x<0 || x>=N) continue;
					if (on[y][x]) unite({0,y,x}, {0,locs[b][1], locs[b][2]});
				}
			}
			on[locs[b][0]][locs[b][1]]=1;

			bool gd=1;
			for (int i=0; i<SZ(check); i++) if (root({0,check[i][0],check[i][1]})!=root({0,post[0],post[1]})) gd=0;

			int diff=locs[b][0]-locs[a][0];
			if (gd) ans=min(ans,diff);
			// else break;
		}
	}
	cout << ans << endl;
}