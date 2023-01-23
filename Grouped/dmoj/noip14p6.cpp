#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int P=1000002937, MAXN=101;
ll A[MAXN], ten[10001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ten[0]=1;
	for (int i=1; i<=10000; i++) {
		ten[i]=ten[i-1]*10%P;
	}

	int N,M; cin>>N>>M;
	for (int i=0; i<=N; i++) {
		string s; cin>>s;
		int dir=1;
		if (s[0]=='-') {
			s.erase(s.begin());
			dir=-1;
		}
		for (int o=0; o<SZ(s); o++) {
			A[i]=(A[i]+dir*ten[SZ(s)-o-1]*(s[o]-'0'))%P;
		}
	}
	vector<int> ans;
	ll sm,em;
	for (int m=1; m<=M; m++) {
		sm=0;
		em=1;
		for (int i=0; i<=N; i++) {
			sm=(sm+A[i]*em)%P;
			em=em*m%P;
		}
		if (sm==0) ans.push_back(m);
	}
	cout << SZ(ans) << endl;
	for (int i : ans) cout << i << endl;
}