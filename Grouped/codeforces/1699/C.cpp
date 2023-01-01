#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<int> P(N);
		int a=0, b=0;
		for (int i=0,e; i<N; i++) {
			cin>>e;
			if (e==0) a=i;
			if (e==1) b=i;
			P[e]=i;
		}
		long long ans=1, md=1e9+7;
		for (int i=2; i<N; i++) {
			if (a>b) swap(a,b);
			if (a<P[i] && P[i]<b) ans*=b-a+1-i, ans%=md;
			else if (P[i]<a) a=P[i];
			else b=P[i];
		}
		cout << ans << endl;
	}	
}