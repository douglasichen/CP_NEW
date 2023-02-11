#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int rnd(int l, int r) {
	return rand()%(r-l+1)+l;
}

int main(int argt, char ** args) {
	srand(time(NULL));
	int Q=200000, sz=1 ,MX=1<<30;
	cout << Q << endl;
	for (int i=0; i<Q; i++) {
		int a=rand()%1000, b=rand()%sz+1, c=(a ? rand()%MX : rand()%sz+1);
		cout << (a ? "Add" : "Query") << ' ' << b << ' ' << c << endl;
		if (a) sz++;
	}
} 