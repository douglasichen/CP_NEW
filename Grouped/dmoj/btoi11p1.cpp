#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<int> ar(N);
	for (int i=0; i<N; i++) cin>>ar[i];
	sort(ar.begin(), ar.end());


	vector<int> V, P;
	V.push_back(-1); // h, psa
	for (int i=0; i<N; i++) {
		V.push_back(ar[i]);
	}

	for (int m=0; m<M; m++) {
		char c; int a,b; cin>>c>>a>>b;
		if (c=='F') {
			for (int &h : V) {
				if (a==0) break;
				if (h>=b) h++, a--;
			}
			sort(V.begin(),V.end());
		}
		else {
			auto y=upper_bound(V.begin(), V.end(), b); y--;
			auto x=lower_bound(V.begin(), V.end(), a); x--;
			cout << (y-x) << endl;
		}
	}
}