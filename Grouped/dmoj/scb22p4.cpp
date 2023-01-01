#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	if (N==1) {
		cout << K << endl;
		return 0;
	}

	long long ans=0;
	while (K) {
		int mnTimes=N/2+N%2;
		if (K>=mnTimes) {
			int i=N-(2-N%2);
			for (; i>0; i-=2) ans+=i;
			ans+=N;
			K-=mnTimes;
		}
		else {
			for (int i=N-1; i>N-1-K; i--) ans+=i;
			K=0;
		}
	}
	cout << ans << endl;
}