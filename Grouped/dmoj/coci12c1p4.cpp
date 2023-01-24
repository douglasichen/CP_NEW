#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXM=300000;
int col[MAXM];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	for (int i=0; i<M; i++) cin>>col[i];
	int L=1, R=1e9, e, left, i, take;
	while (L<R) {
		e=L+R>>1, left=N;
		for (i=0; i<M; i++) {
			take=(col[i]+e-1)/e;
			left-=take;
		}
		if (left<0) L=e+1;
		else R=e;
	}
	cout << R << endl;
}