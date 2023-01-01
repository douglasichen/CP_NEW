#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	// int T; cin>>T;
	while (1) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		bool A=(a^b)<(c^d), B=(a^d)>(c^b);
		cout << (A==B) << endl;
	}

}