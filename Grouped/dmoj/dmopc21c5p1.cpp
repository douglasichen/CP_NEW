#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    int N; cin>>N;
    if (N<5) {
		if (N==1) cout << 1 << endl;
		else cout << -1 << endl;
        return 0;
    }
	cout << 1;
    for (int i=3; i<=N; i+=2) if (i!=5) cout << ' ' << i;
    cout << ' ' << 5 << ' ' << 4;
    for (int i=2; i<=N; i+=2) if (i!=4) cout << ' ' << i;
    cout << endl;
}