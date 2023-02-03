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

	int N=10, M=(N-1)*2, MAXD=2;
	int D=rand()%MAXD+1, A=D;
	cout << N << " " << M << " " << D << endl;
	for (int i=2; i<=N; i++) {
		int a=i, b=rand()%(i-1)+1, c=rand()%A+1;
		cout << a << ' ' << b << ' ' << c << endl;
	}
	for (int i=2; i<=N; i++) {
		int a=i, b=rand()%(i-1)+1, c=rand()%A+1;
		cout << a << ' ' << b << ' ' << c << endl;
	}
}