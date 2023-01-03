#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int TSZ=1<<20;
ll pre[TSZ*2], suf[TSZ*2], ar[TSZ];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(pre, 0x7f7f7f7f, sizeof(pre));
	memset(suf, 0x7f7f7f7f, sizeof(suf));

	int N,Q; cin>>N>>Q;
	for (int i=0; i<N; i++) cin>>ar[i], pre[TSZ+i]=ar[i]+i, suf[TSZ+i]=ar[i]+(N-i-1);
	for (int i=TSZ-1; i; i--) pre[i]=merge(pre[i<<1], pre[i<<1|1]), suf=merge(suf[i<<1], suf[i<<1|1]);

	while (Q--) {
		int m, k; cin>>m>>k; k--;
		if (m==1) {
			int x; cin>>x;
			upt(1, 0, TSZ, k, x-ar[k]);
		}
		else {
			cout << min(queryPre(1, 0, TSZ, 0, k)-)
		}
	}
}