#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans=INT_MIN;
	int N,M; cin>>N>>M;
	vector<vector<int>> V(N, vector<int>(2));
	vector<int> A(N);
	for (int i=0; i<N; i++) cin>>V[i][0]>>V[i][1];
	iota(A.begin(), A.end(), 0);
	sort(A.begin(), A.end(), [&](int a, int b) {
		return V[a][0]>V[b][0];
	});

	auto srt=[&](int a, int b) {
		return V[a][1]<V[b][1];
	};
	priority_queue<int, vector<int>, decltype(srt)> pq(srt);
	for (int i=0; i<N; i++) {
		pq.push(A[i]);
		if (pq.size()<M) continue;
		if (pq.size()>M) pq.pop();
		ans=max(ans, V[A[i]][0] - V[pq.top()][1]); 
	}
	cout << ans << endl;
}