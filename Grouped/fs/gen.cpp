#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {

	srand(time(NULL));
	
	const int MAXN=20;
	int N=MAXN, K=rand()%(N-1)+1;
	cout << N << " " << K << "\n";

	for (int i=0; i<N; i++) cout << rand()%MAXN+1 << ' ';
	cout << endl;
}