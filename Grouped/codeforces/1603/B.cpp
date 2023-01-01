#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int X,Y,N; cin>>X>>Y;
		if (X>Y) N=X+Y;
		else if (X<Y) N=Y-Y%X/2;
		else N=X;
		cout << (N) << endl;
	}	
}