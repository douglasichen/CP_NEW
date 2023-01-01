#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,T,Q; cin>>N;
	vector<vector<int>> P(N,vector<int>(2));
	for (int i=0; i<N; i++) cin>>P[i][0]>>P[i][1];
	
	cin>>T;
	vector<vector<int>> F(T,vector<int>(2));
	for (int i=0; i<T; i++) {
		char c; cin>>c>>F[i][1];
		F[i][0]=(c=='X');
	}
	cin>>Q;
	for (int i=0; i<Q; i++) {
		int pI, tI; cin>>pI>>tI; pI--, tI--;
		vector<int> p=P[pI];
		for (int i=0; i<=tI; i++) {
			vector<int> flip=F[i];
			if (flip[0]) { // flip on x
				p[0]=flip[1]+flip[1]-p[0];
			}
			else {	// flip on y
				p[1]=flip[1]+flip[1]-p[1];
			}
		}
		cout << p[0] << ' ' << p[1] << endl;
	}

}