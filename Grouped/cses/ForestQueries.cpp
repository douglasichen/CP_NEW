#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1001;
int ar[MAXN][MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(ar,0);

	int N,Q; cin>>N>>Q;
	char c;
	for (int y=1; y<=N; y++) {
		for (int x=1; x<=N; x++) {
			cin>>c;
			ar[y][x]=ar[y-1][x]+ar[y][x-1]-ar[y-1][x-1]+(c=='*');
		}
	}
	for (int i=0; i<Q; i++) {
		int a,b,c,d; cin>>a>>b>>c>>d;
		cout << ar[c][d]-ar[c][b-1]-ar[a-1][d]+ar[a-1][b-1] << endl;
	}
}