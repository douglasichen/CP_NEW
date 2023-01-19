#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MX=128+1;
ll ar[MX*3][MX*3], psa[MX*3][MX*3];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(ar,0);
	ms(psa,0);

	int D,N; cin>>D>>N;
	for (int i=0; i<N; i++) {
		int x,y,k; cin>>x>>y>>k;
		ar[y+MX][x+MX]=k;
	}

	for (int y=MX; y<MX*3; y++) {
		for (int x=MX; x<MX*3; x++) {
			psa[y][x]=psa[y-1][x]+psa[y][x-1]-psa[y-1][x-1]+ar[y][x];
		}
	}
	vector<ll> v;
	ll sm;
	for (int y=MX; y<MX*2; y++) {
		for (int x=MX; x<MX*2; x++) {
			// the sum at this location as a centre
			sm=psa[y+D][x+D]-psa[y+D][x-D-1]-psa[y-D-1][x+D]+psa[y-D-1][x-D-1];
			v.push_back(sm);
		}
	}

	sort(v.begin(),v.end(),greater<ll>());

	int cnt=1;
	for (int i=1; i<SZ(v); i++) {
		if (v[i]!=v[i-1]) break;
		cnt++;
	}
	cout << cnt << ' ' << v[0] << endl;
}