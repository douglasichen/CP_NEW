#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool solve(string a, string b) {
	if (a.substr(a.size()-1,1)=="7" && b.size()>1 && b.substr(b.size()-2, 2)=="11") {
		return 1;
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	while (N--) {
		string a,b; cin>>a>>b;
		bool gd=1;
		if (solve(a,b) || solve(b,a)) {
			if (a.size()>1 && a.substr(a.size()-2,2)=="17" || 
				b.size()>1 && b.substr(b.size()-2,2)=="17") gd=0;
		}
		else gd=0;
		cout << (gd ? "YES" : "NO") << endl;
	}	
}