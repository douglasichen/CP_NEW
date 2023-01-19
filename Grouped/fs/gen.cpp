#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {

	srand(time(NULL));
	
<<<<<<< HEAD
	cout << 8 << " " << rand()%3+2 << "\n";
	for (int i=0; i<8; i++) cout << rand()%8+1 << " "; cout << endl;
=======
	const int MAXN=7;	
	int N=rand()%MAXN+3, C=rand()%3+N;

	cout << N << " " << C << endl;
	for (int i=0; i<N; i++)
		cout << rand()%C << ' ';
	cout << endl;
>>>>>>> bf4a286ae018ece9f90054e7bfc406e9865d112d

}