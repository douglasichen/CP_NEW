#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


vector<vector<long long>> re(vector<int> &V, int &M) {
	vector<vector<long long>> ans;
	for (int i : V) {
		long long at=i, cnt=1;
		while (at%M==0) {
			at/=M;
			cnt*=M;
		}
		if (!ans.size()) ans.push_back({cnt, at});
		else {
			if (ans.back()[1]==at) ans.back()[0]+=cnt;
			else ans.push_back({cnt,at});
		}
	}
	return ans;
}

bool solve() {
	int N,M; cin>>N>>M;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin>>A[i];

    int K; cin>>K;
    vector<int> B(K);
    for (int i=0; i<K; i++) cin>>B[i];

	return re(A,M)==re(B,M);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		bool ans=solve();
		cout << (ans ? "YES" : "NO") << endl;

	}	
}