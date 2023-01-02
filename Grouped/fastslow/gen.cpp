#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {
	srand(time(NULL));
	
	int V=10, N=V, Q=V;
	cout << N << ' ' << Q << endl; 
	for (int i=0; i<N; i++) cout << rand()%V << ' '; cout << endl;
	while (Q--) {
		int X=rand()%3+1, A=rand()%N, B=rand()%(N-A)+A; A++, B++;
		
		cout << X << ' ';
		if (X==3) cout << A << ' ' << B << '\n';
		else cout << A << ' ' << B << ' ' << rand()%V+1 << endl;
	}
	return 0;
}