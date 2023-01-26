#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N,M; cin>>N;
		for (int i=0; i<N; i++) cin>>dam[i];
		cin>>M;
		for (int i=0; i<M; i++) cin>>hel[i];

		int a=0, b=0, ans=0, alive=M;
		while (alive) {
			if (hel[b%M]>0) {
				hel[b%M]-=dam[a%N];
			}
			a++;
			if (hel[b%M]<=0) b++;
		}

		cout << ans << endl;
	}
}