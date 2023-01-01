#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	long long sm=0;
	for (int i=0,a; i<N; i++) {
		cin>>a, sm+=a;
		cout << sm << endl;
	}	
}