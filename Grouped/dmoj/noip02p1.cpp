#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=100;
int ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,sm=0; cin>>N;
	for (int i=0; i<N; i++) cin>>ar[i], sm+=ar[i];
	sm/=N;
	for (int i=0; i<N; i++) ar[i]=sm-ar[i];

	int cnt=0;
	for (int i=0; i<N-1; i++) {
		if (ar[i]) cnt++, ar[i+1]+=ar[i];
	}
	cout << cnt << endl;
}