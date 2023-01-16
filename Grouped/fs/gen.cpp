#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {

	srand(time(NULL));
	
	const int MAXN=7;	
	int N=rand()%MAXN+3, C=rand()%3+N;

	cout << N << " " << C << endl;
	for (int i=0; i<N; i++)
		cout << rand()%C << ' ';
	cout << endl;

}