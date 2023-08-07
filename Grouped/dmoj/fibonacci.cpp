#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())
#define A first
#define B second

const ull MD=1e9+7;

pair<ull,ull> logP[64];
ull logT[64];

pair<ull,ull> comb(pair<ull,ull> x, pair<ull,ull> y) {
	return {x.A*y.A%MD + x.B*y.B%MD*5%MD, (x.A*y.B%MD + x.B*y.A%MD)%MD};
}

ull fpw(ull a, ull b) {
	ull x=a, ans=1;
	while (b) {
		if (b&1) {
			ans=ans*x%MD;
		}
		x=x*x%MD;
		b>>=1;
	}
	return ans;
}

ull div(ull a, ull b) {
	return a*fpw(b%MD, MD-2)%MD;
}

void printP(pair<ull,ull> p) {
	cout << p.A << ' ' << p.B << endl << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ull N; cin>>N;

	logP[0]={1,1};
	for (int i=1; i<64; i++) logP[i]=comb(logP[i-1], logP[i-1]);

	ull at=N;
	pair<ull,ull> P={1,1};
	bool init=0;
	for (int i=0; i<64 && at; i++, at>>=1) {
		if (at&1) {
			if (!init) P=logP[i], init=1;
			else P=comb(P,logP[i]);
		}
	}
	
	logT[0]=2;
	for (int i=1; i<64; i++) logT[i]=logT[i-1]*logT[i-1]%MD;
	
	at=N;
	ull twos=1;
	for (int i=0; i<64 && at; i++, at>>=1) {
		if (at&1) {
			twos=twos*logT[i]%MD;
		}
	}

	ull ans=div(P.B*2%MD,twos);
	cout << ans << endl;
}