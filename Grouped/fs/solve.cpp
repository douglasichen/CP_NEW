#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,Q; cin>>N>>Q;
	int ar[N][N];
	char c;
	for (int y=0; y<N; y++)
		for (int x=0; x<N; x++)
			cin>>c, ar[y][x]=(c=='*');	

	while (Q--) {
		int m, y1, x1; cin>>m>>y1>>x1; y1--, x1--;
		if (m==1) {
			ar[y1][x1]^=1;
		}
		else {
			int y2, x2, ans=0; cin>>y2>>x2;
			for (int y=y1; y<y2; y++)
				for (int x=x1; x<x2; x++)
					ans+=ar[y][x];
			cout << ans << endl;
		}
	}
}