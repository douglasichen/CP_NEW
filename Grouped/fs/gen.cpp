#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {

	srand(time(NULL));
	
	const int MAXN=20;
	int N=MAXN, K=rand()%(N-1)+1;
	cout << N << " " << K << "\n";
	cout << 8 << " " << rand()%3+2 << "\n";
	for (int i=0; i<8; i++) cout << rand()%8+1 << " "; cout << endl;
	const int MAXN=7;	
	int N=rand()%MAXN+3, C=rand()%3+N;

	for (int i=0; i<N; i++) cout << rand()%MAXN+1 << ' ';
	cout << endl;
}