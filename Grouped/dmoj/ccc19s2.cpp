#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<int> primes, isP(2e6,1); isP[1]=0, isP[0]=0;
	for (int i=2; i<2e6; i++) {
		if (!isP[i]) continue;
		int at=i+i;
		primes.push_back(i);
		for (; at<2e6; at+=i) isP[at]=0;
	}
	
	int T; cin>>T;
	while (T--) {
		int N; cin>>N; N*=2;
		for (int i=0; i<primes.size(); i++) {
			int A=primes[i], B=N-A;
			if (B>0 && isP[B]) {
				cout << A << ' ' << B << endl;
				break;
			}
		}
	}
}