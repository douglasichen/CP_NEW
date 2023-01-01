#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(), V.end());
	vector<int> ans;
	for (int i=0; i<N/2; i++) {
		ans.push_back(V[N/2-i-1+(N&1)]);
		ans.push_back(V[N/2+i+(N&1)]);
	}
	if (N&1) ans.push_back(V[0]);
	for (int i : ans) cout << i << ' '; cout << endl;
}