#include <bits/stdc++.h>
using namespace std;

int main(int argt, char ** args) {
	if (argt!=4) {
		cout << "invalid parameters\n";
		return 0;
	}
	int a=stoi(args[1]), b=stoi(args[2]), seed=stoi(args[3]);

	srand(seed);
	int L=a, R=a, N=a, X=a, Q=b, type;
	cout << N << endl << Q << endl;
	while (Q--) {
		int type=rand()%2, l=rand()%L, r=rand()%(R-l)+l, x=rand()%X;
		cout << type << ' ' << l << ' ' << r << ' ' << x << endl;
	}
	return 0;
}