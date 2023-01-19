#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2e5;
int md=10007;
vector<int> G[MAXN], psa[MAXN];
ll W[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	for (int i=0; i<N-1; i++) {
		int a,b; cin>>a>>b; a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i=0; i<N; i++) cin>>W[i];

	for (int i=0; i<N; i++) {
		sort(G[i].begin(), G[i].end(), [&](int a, int b) {
			return W[a]>W[b];
		});
	}

	ll mx=0,ans=0, sm;
	for (int i=0; i<N; i++) {
		sm=0;
		for (int o : G[i]) sm+=W[o];
		for (int a=0; a<SZ(G[i]); a++) {
			ans+=(sm-W[G[i][a]])*W[G[i][a]];
			for (int x=0; x<SZ(G[i]); x++) {
				if (x!=a) {
					mx=max(mx, W[G[i][a]]*W[G[i][x]]);
					break;
				}
			}
		}
	}
	cout << mx << ' ' << ans%md << endl;
}