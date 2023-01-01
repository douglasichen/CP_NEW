#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; cin>>S;
	int a=1, cnt=1;
	for (int i=1; i<S.size(); i++) {
		if (S[i]==S[i-1]) cnt++;
		else cnt=1;
		a=max(a,cnt);
	}	
	cout << a << '\n';
}