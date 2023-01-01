#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool good(int N, int M, int K, vector<int> V) {
	for (int i=0; i<K; i++) V[i]/=M;
	sort(V.begin(), V.end(), greater<int>());
	for (int i : V) {
		if (i<=1) return 0;
		if (i>=N) {
			if (N>1) N=0;
			else {
				if (V[0]>2) N=0;
				else return 0;
			}
		}
		else N-=i;
		if (N==0) return 1;
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N,M,K; cin>>N>>M>>K;
		vector<int> V(K);
		for (int i=0; i<K; i++) cin>>V[i];
		if (good(N,M,K,V) || good(M,N,K,V)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}	
}