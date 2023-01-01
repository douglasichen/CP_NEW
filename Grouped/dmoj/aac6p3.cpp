#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<long long> psa(N+1);
	for (int i=1; i<=N; i++) cin>>psa[i], psa[i]+=psa[i-1];
	
	long long ans=0;
	int P=1e7;
	vector<int> F(P<<1);
	for (int o=1; o<=100; o++) {
		for (int i=0; i<=N; i++) {
			long long at=psa[i]-o*i+P;
			ans+=F[at];
			F[at]++;
		}
		for (int i=0; i<=N; i++) F[psa[i]-o*i+P]=0;
	}
	cout << ans << endl;
	
}