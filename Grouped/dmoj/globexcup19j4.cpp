#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=1e5;
int ar[MAXN];
map<int,int> fr;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,K; cin>>N>>M>>K;
	vector<int> ve;
	for (int i=0; i<N; i++) {
		int a; cin>>a;
		if (fr[a]==0) ve.push_back(a);
		fr[a]++;
	}
	sort(ve.begin(), ve.end(), [&](int a, int b) {
		return fr[a]>fr[b];
	});
	ll ans=0;
	for (int i : ve) {
		int take=min(fr[i],K);
		ans+=ll(take)*(take-1)/2;
		K-=take;

	}
	cout << ans << endl;
}