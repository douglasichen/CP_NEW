#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	int mn=M+1, x;
	for (int i=4; i<M; i++) {
		int y=i+(N+i)/(2*i+1);
		if (y<mn) {
			x=i;
			mn=y;
		}

		int k=(N+2*i)/(2*i+1)+i;
		cout << k << ' ';
	}
	cout << endl;
	
	vector<int> v;
	for (int i=1; i<=x; i++) v.push_back(i);
	for (int i=x+x*2+1; i<=N; i+=2*x+1) v.push_back(i);
	if (SZ(v)<M) v.push_back(v.back()+x);

	cout << SZ(v) << endl;
	for (int i=0; i<SZ(v); i++) {
		cout << v[i] << (i<SZ(v)-1 ? ' ' : '\n');
	}
}