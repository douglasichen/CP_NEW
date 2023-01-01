#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,J; cin>>N>>M>>J;
	vector<vector<int>> V(M, vector<int>(2));	// time, loc
	for (int i=0; i<M; i++) cin>>V[i][1]>>V[i][0];
	sort(V.begin(), V.end());

	int ans=0, p=0;
	set<int, greater<int>> S;
	for (int i=0; p+J<=N && i<M; i++) {
		ans=V[i][0];
		S.emplace(V[i][1]);
		while (p+J<=N) {
			auto it=S.lower_bound(p+J);
			if (it!=S.end()) {
				if ((*it)>p) p=*it;
				else break;
			}
			else break;
		}
	}
	if (p+J<=N) ans=-1;
	cout << ans << endl;

}