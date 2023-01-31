#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	srand(time(0));

	int T=1, mx=1000, mx2=100000;
	cout << T << endl;
	int N=rand()%mx+1, S=rand()%(N*(N+1)/2)+10;
	cout << N << " " << S << endl;
}