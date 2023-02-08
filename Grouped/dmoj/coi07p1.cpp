#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=1e5;
double ar[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	double K; cin>>K;
	int N; cin>>N;
	for (int i=0; i<N; i++) cin>>ar[i];

	double L=0, R=1e9;
	while (R-L>0.0001) {
		double t=(L+R)/2, past=ar[0]+t;
		bool gd=1;		
		for (int i=1; i<N; i++) {
			double need=past+K;
			if (need<ar[i]) {
				if (ar[i]-need>t) gd=0;
				past=need;
			}
			else {
				past=min(need,ar[i]+t);
			}
		}
		if (gd) R=t;
		else L=t;
	}
	cout << fixed << setprecision(4) << R << endl;
}