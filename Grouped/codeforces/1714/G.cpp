#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T,N; cin>>T;
	vector<ll> A,B; A.assign(2e5,0); B=A;
	vector<vector<int>> G;
	while (T--) {
		cin>>N;
		G.assign(N,{});
		for (int i=1,p,a,b; i<N; i++) {
			cin>>p>>a>>b; p--;
			G[p].push_back(i);
			A[i]=a, B[i]=b;
		}
		
		vector<ll> V, ans(N-1);
		stack<vector<ll>> S;
		S.push({0,0,0});
		while (!S.empty()) {
			vector<ll> top=S.top(); S.pop();
			while (V.size() && V.size()>top[1]) V.pop_back();
			if (V.size()) V.push_back(V.back()+B[top[0]]);
			else V.push_back(0);
			// V.push_back(top[0]);
			for (int child : G[top[0]]) S.push({child, top[1]+1, top[2]+A[child]});

			// for (ll i : V) cout << i << ' '; cout << endl;

			if (!top[0]) continue;
			auto it=lower_bound(V.begin(), V.end(), top[2]);
			if (it==V.end() || *it>top[2]) it--;
			ans[top[0]-1]=it-V.begin();
		}
		for (ll i : ans) cout << i << " "; cout << endl;
	}
}