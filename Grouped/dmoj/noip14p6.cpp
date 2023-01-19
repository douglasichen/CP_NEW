#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=101;
int A[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	for (int i=0; i<=N; i++) cin>>A[i];

	vector<int> ans;
	for (int m=1; m<=M; m++) {
		int p=1, res=0;
		for (int i=0; i<=N; i++) {
			res+=A[i]*p;
			p*=m;
		}
		if (res==0) ans.push_back(m);
	}
	cout << SZ(ans) << endl;
	for (int i=0; i<SZ(ans); i++) {
		cout << ans[i] << endl;
	}
}