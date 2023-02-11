#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=1000;
int ar[MAXN][MAXN], row[MAXN], col[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(ar,0);
	ms(row,0);
	ms(col,0);

	int N,M; cin>>N>>M;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			int a; cin>>a;
			if (a) row[y][x++, col[x]++;
			ar[y][x]=a;
		}
	}

	int ans=0;
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			if (!ar[y][x] && (row[y]+col[x])) ans++;
		}
	}
	cout << ans << endl;

}