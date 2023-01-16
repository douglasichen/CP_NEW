#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=200;
int ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,C; cin>>N>>C;
	for (int i=0; i<N; i++) cin>>ar[i];
	ll ans=0;
	for (int a=0; a<N; a++) {
		for (int b=a+1; b<N; b++) {
			for (int c=b+1; c<N; c++) {
				vector<int> v={ar[a],ar[b],ar[c]};
				sort(v.begin(), v.end());
				int x=max({v[1]-v[0], v[2]-v[1], v[0]+C-v[2]});
				if (x<(C+1)/2) ans++;
			}
		}
	}
	cout << ans << endl;
}