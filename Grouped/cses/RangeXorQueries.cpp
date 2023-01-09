#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=2e5+1;
int ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ar[0]=0;
	int N,Q; cin>>N>>Q;
	for (int i=1; i<=N; i++) cin>>ar[i], ar[i]^=ar[i-1];
	for (int i=0; i<Q; i++) {
		int a,b; cin>>a>>b; a--;
		cout << (ar[b]^ar[a]) << endl;
	}
}