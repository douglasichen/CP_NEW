#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
`
	int N,Q; cin>>N>>Q;
	vector<long long> T(N*2);
	for (int i=0; i<N; i++) cin>>T[i+N];
	for (int i=N-1; i>0; i--) T[i]=T[i*2]+T[i*2+1];
	vector<long long> ans;
	for (int i=0; i<Q; i++) {
		int x,a,b; cin>>x>>a>>b; a--;
		if (x==1) {
			long long dif=b-T[a+=N]; T[a]=b;
			while (a>1) T[a>>=1]+=dif;
		}
		else {
			long long res=0;
			for (a+=N, b+=N; a<b; a>>=1, b>>=1) {
				if (a&1) res+=T[a++];
				if (b&1) res+=T[--b];
			}
			ans.push_back(res);
		}
	}
	for (long long i : ans) cout << i << endl;
}