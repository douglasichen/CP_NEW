#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(), V.end(), greater<int>());
	pair<long long,int> ans={0,0};
	long long cost=0;
	for (int i=0; i<N; i++) {
		cost=(long long)V[i]*(i+1);
		if (cost>=ans.first) ans={cost,V[i]};
	}
	cout << ans.first << ' ' << ans.second << endl;
}