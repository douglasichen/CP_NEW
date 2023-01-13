#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

int N, fr[5+1];

void solve(vector<int> V, int x) {
	fr[V[0]]--;

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i], fr[V[i]]++;	


	double ans=0;
	for (int i=1; i<=5; i++) {
		if (fr[i]) ans+=solve(V,i);
	}
}