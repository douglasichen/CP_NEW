#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	

	vector<bool> nP(148734+1);
	vector<int> primes;
	for (int i=2; i<nP.size(); i++) {
		if (nP[i]) continue;
		primes.push_back(i);
		int at=i;
		while (at<nP.size()) nP[at]=1, at+=i;
	}
	reverse(primes.begin(), primes.end());

	long long ans=0;
	int N,X; cin>>N>>X;
	for (int sub=0; sub<2; sub++) {
		N-=sub;
		for (int a=0, b=0; a<primes.size(); a++) {
			while (X*b+primes[a]<=N) b++;
			ans+=b;
		}
	}
	cout << ans << endl;
}