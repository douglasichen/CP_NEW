#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {

	srand(time(NULL));
	
	int V=1000;
	int N=8, Q=N*(N+1)/2*3;

	cout << N << ' ' << Q << '\n';
	for (int i=0; i<N; i++) cout << rand()%V+1 << ' ';
	cout << endl;
	
	for (int a=1; a<=N; a++) {
		for (int b=a; b<=N; b++) {
			cout << 1 << ' ' << a << ' ' << b << ' ' << rand()%10+1 << '\n';

			int x=rand()%N, y=rand()%(N-x)+x; x++, y++;
			cout << 2 << ' ' << x << ' ' << y << ' ' << rand()%10+1 << '\n';
			
			x=rand()%N, y=rand()%(N-x)+x; x++, y++;
			cout << 3 << ' ' << x << ' ' << y << '\n';
		}
	}
}