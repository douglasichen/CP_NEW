#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {

	srand(time(NULL));
	
	int V=10;
	int N=4, Q=10;

	cout << N << ' ' << Q << '\n';
	for (int y=0; y<N; y++)
		for (int x=0; x<N; x++) 
			cout << (rand()%2==1 ? "*" : ".") << (x==N-1 ? "\n" : "");
	
	while (Q--) {
		int m=rand()%2+1, y1=rand()%N, x1=rand()%N;
		if (m==1) {
			cout << m << " " << y1+1 << " " << x1+1 << "\n";
		}
		else {
			int y2=rand()%(N-y1)+y1, x2=rand()%(N-x1)+x1;
			cout << m << " " << y1+1 << " " << x1+1 << " " << y2+1 << " " << x2+1 << "\n";
		}
	}
}