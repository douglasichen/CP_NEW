#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,K; cin>>N>>M>>K;
	vector<vector<int>> V(N+2, vector<int>(M+2));
	for (int i=0; i<K; i++) {
		int a,b; cin>>a>>b;
		V[a][b]=1;
	}
	int ans=0;
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=M; x++) {
			if (!V[y][x]) {
				int sm=0;
				for (int a=y-1; a<=y+1; a++)
					for (int b=x-1; b<=x+1; b++)
						sm+=V[a][b];
				if (sm>=3) ans++;
					
			}
		}
	}
	cout << ans << endl;

}