#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=2e4;
const int MAXM=1e3+1;

int ar[MAXN];
vector<int> f[MAXM];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	for (int i=0; i<N; i++) cin>>ar[i];
	
	int ans=0;
	for (int k=N/2; k>=0; k--) {
		for (int i=0; i<=M; i++) f[i].clear();
		for (int i=0; i<2*k; i++)
			f[ar[i]].push_back(i);
		
		int cnt=0;
		for (int a=1, b=2; a<=M && b<=M; ) {
			while (a<=M && !SZ(f[a])) a++;
			while (b<=M && (b<=a || !SZ(f[b]) || f[b].back()<f[a].back())) b++;
			if (a<=M && b<=M) f[a].pop_back(), f[b].pop_back(), cnt++;
		}
		if (cnt==k) {
			ans=k;
			break;
		}
	}
	cout << ans << endl;
}