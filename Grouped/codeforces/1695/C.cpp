#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	int N,M;
	vector<vector<int>> mx(1001, vector<int>(1001)), mn=mx;
	vector<vector<short>> V(1001, vector<short>(1001));
	for (int t=0; t<T; t++) {
		cin>>N>>M;
		for (int y=1; y<=N; y++) for (int x=1; x<=M; x++) cin>>V[y][x];
		if ((N+M-1)&1) {
			cout << "NO" << endl;
			continue;
		}
		for (int y=1; y<=N; y++) mx[y][1]=V[y][1]+mx[y-1][1], mn[y][1]=V[y][1]+mn[y-1][1];
		for (int x=1; x<=M; x++) mx[1][x]=V[1][x]+mx[1][x-1], mn[1][x]=V[1][x]+mn[1][x-1];
		for (int y=2; y<=N; y++) for (int x=2; x<=M; x++)
			mx[y][x]=max(mx[y-1][x],mx[y][x-1])+V[y][x], mn[y][x]=min(mn[y-1][x],mn[y][x-1])+V[y][x];
		if (mn[N][M]<=0 && 0<=mx[N][M]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}