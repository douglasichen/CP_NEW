#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int A,B; cin>>A>>B;
	cout << "Sun Mon Tue Wed Thr Fri Sat\n";
	
	int at=1;
	for (int i=0; i<A-1; i++) cout << "    ";
	for (; A<=7; A++, at++) cout << "  " << at << (A==7 ? '\n' : ' ');
	for (; at<=B; at++, A++) {
		cout << ' ';
		if (at<10) cout << ' ';
		cout << at << (A%7==0 || at==B ? '\n' : ' ');
	}
	
}
