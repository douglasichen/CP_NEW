#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=3000;
int ar[2][MAXN][MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	for (int y=0; y<N; y++)
		for (int x=0; x<y+1; x++)
			cin>>ar[0][y][x];

	int cnt=0;
	int k2=1, I=0, sK=1;
	for (int k=2, k2=1, i=1; k<K; k=(k*3+1)>>1, i++) {
		for (int y=0; y<=N-k; y++) {
			for (int x=0; x<y+1; x++) {
				ar[1][y][x]=max({ar[0][y][x], 
								ar[0][y+k-k2][x], 
								ar[0][y+k-k2][x+k-k2]});
			}
		}
		k2=k;
		sK=k;
		I=i;
		swap(ar[0],ar[1]);
	}

	ll ans=0;
	for (int y=0; y<=N-K; y++) {
		for (int x=0; x<y+1; x++) {
			ans+=max({ar[0][y][x],
						ar[0][y+K-sK][x],
						ar[0][y+K-sK][x+K-sK]});
		}
	}
	cout << ans << endl;
}