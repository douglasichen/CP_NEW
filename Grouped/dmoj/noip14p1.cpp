#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=200;
int arA[MAXN], arB[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<vector<int>> mat={
		{0,2,1,1,2},
		{1,0,2,1,2},
		{2,1,0,2,1},
		{2,2,1,0,1},
		{1,1,2,2,0},
	};

	int a=0,b=0;
	int N,A,B; cin>>N>>A>>B;
	for (int i=0; i<A; i++) cin>>arA[i];
	for (int i=0; i<B; i++) cin>>arB[i];
	for (int i=0; i<N; i++) {
		int val=mat[arA[i%A]][arB[i%B]];
		if (val==1) a++;
		else if (val==2) b++;

		// cout << a << ' ' << b << endl;
	}
	cout << a << ' ' << b << endl;
}