#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<vector<int>> G(N+1);
	vector<int> D(N+1);
	for (int i=0,a,b,d; i<N-1; i++) cin>>a>>b>>d, D[b]=d, G[a].push_back(b);

	vector<int> S(K);
	for (int i=0; i<K; i++) cin>>S[i];
	sort(S.begin(),S.end());

	auto srt=[&](int &a, int &b) {return D[a]<D[b];};
	vector<vector<int>> A(N+1,vector<int>(2));
	A[1]={1,K};
	deque<int> dq; dq.push_back(1);
	while (!dq.empty()) {
		int back=dq.back(), mn=A[back][0], mx=A[back][1]; dq.pop_back();
		sort(G[back].begin(), G[back].end(), srt);

		if (G[back].size()) {
			int l=1,r=1;
			for (int i=0; i<G[back].size()-1; i++) {
				int a=G[back][i], b=G[back][i+1], mid=(D[b]+D[a])>>1;
				auto it=upper_bound(S.begin(), S.end(), mid);
				r=it-S.begin();
				A[a]={max(l,mn),min(r,mx)};
				l=r+1;

				dq.push_front(a);
			}
			
			r=K;
			int lst=G[back].back();
			A[lst]={max(mn,l),min(mx,r)};
			dq.push_front(lst);
		}
	}

	// for (int i=1; i<=N; i++) cout << i << ": " << A[i][0] << " " << A[i][1] << endl;
	for (int i=1,ans; i<=N; i++) {
		ans=max(0, A[i][1]-A[i][0]+1);
		cout << ans << (i<N ? " " : "\n");
	}
}