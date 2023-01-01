#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);
	
	int INF=1e9;
	int N,ans=1; cin>>N;
	vector<int> V(N+2), go(N+1);
	V[0]=-INF, V[N+1]=INF;
	for (int i=1; i<=N; i++) cin>>V[i];
	sort(V.begin(), V.end());
	
	for (int i=1; i<=N; i++) {
		vector<bool> vis(N+2);
		int at=i;
		int L=at, R=at;
		while (!vis[at]) {
			vis[at]=1;
			at=(V[at]-V[at-1]<=V[at+1]-V[at] ? at-1 : at+1);
			if (at<1 || at>N) break;
			L=min(L,at);
			R=max(R,at);
			// cout << L << " " << R << endl;
 		}
		go[L]=max(go[L],R);
	}

	vector<int> mx(N+1);
	for (int i=1; i<=N; i++) mx[i]=max(go[i], mx[i-1]);//, cout << mx[i] << ' '; cout << endl;
	
	int back=go[1];
	while (back<N) {
		back=mx[back+1];
		ans++;
	}
	cout << ans << endl;
}