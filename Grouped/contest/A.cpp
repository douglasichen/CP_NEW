#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=1e5;

int ar[MAXN], br[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(ar,0);
	ms(br,0);

	int N; cin>>N;
	for (int i=0; i<N; i++) cin>>ar[i];
	for (int i=1; i<N; i++) if (ar[i]>=ar[i-1]) br[i]=1;

	int mx=0, l=0;
	for (int i=1; i<N; i++) {
		if (br[i]) l++;
		else l=0;
		mx=max(l,mx);
	}
	cout << mx+1 << endl;
}