#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	vector<vector<int>> P(N+1,vector<int>(N+1));
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=N; x++) {
			char c; cin>>c;
			P[y][x]+=c=='*';
		}
	}
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=N; x++) P[y][x]+=P[y-1][x]+P[y][x-1]-P[y-1][x-1];
	}
	for (int i=0; i<Q; i++) {
		int y1,x1,y2,x2; cin>>y1>>x1>>y2>>x2;
		int ans=P[y2][x2]-P[y1-1][x2]-P[y2][x1-1]+P[y1-1][x1-1];
		cout << ans << endl;
	}

}