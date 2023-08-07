#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=300000;
int A[MAXN], B[MAXN], cnt[MAXN], ord[MAXN], ans[MAXN];
ll niceness=0;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(cnt,0);

	int N; cin>>N;
	for (int i=0; i<N; i++) cin>>A[i];
	for (int i=0; i<N; i++) cin>>B[i];
	sort(B,B+N);
	for (int i=1; i<N; i++) {
		if (A[i-1]<A[i]) cnt[i-1]--, cnt[i]++;
		else cnt[i-1]++, cnt[i]--;
	}
	iota(ord,ord+N,0);
	sort(ord,ord+N,[&](int a, int b) {
		if (cnt[a]==cnt[b]) return a<b;
		return cnt[a]<cnt[b];
	});

	vector<int> qu;
	for (int i=0; i<N; i++) if (cnt[ord[i]]==0) qu.push_back(B[i]);
	int L=0, R=SZ(qu)-1;

	for (int i=0; i<N; i++) {
		int o=ord[i];
		niceness+=cnt[o]*B[i];

		if (cnt[o]!=0) ans[o]=B[i];
		else {
			if (A[o-1]<A[o]) ans[o]=qu[L++];
			else ans[o]=qu[R--];
		}
	}
	
	
	cout << niceness << endl;
	for (int i=0; i<N; i++) cout << ans[i] << ' '; cout << endl;
}