#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {

	srand(time(NULL));
	
	int N=10, M=10, K=5;
	cout << N << " " << M << " " << K << endl;
	for (int i=0; i<N; i++) {
		int a=rand()%(N-1)+1, b=rand()%(N-1)+1;
		cout << a << ' ' << b << endl;
	}

	int I=0;
	for (int i=1; K && i<N; i++) {
		I=i;
		if (N-i+1==K) break;
		bool hit=rand()%N;
		if (hit==0) {
			int x=i, a=rand()%(M-2), b=rand()%(M-a)+a;
			cout << x << ' ' << a << ' ' << b << endl;
			K--;
		}
	}
	for (int i=I; i<N; i++) {
		int x=i, a=rand()%(M-2), b=rand()%(M-a)+a;
		cout << x << ' ' << a << ' ' << b << endl;
	}
	// for (int k=0; k<K; k++) {
	// 	int x=rand()%(N-1)+1, a=rand()%(N-2), b=a+rand()%(N-a-1)+1;
	// 	cout << x << ' ' << a << ' ' << b << endl;
	// }
}