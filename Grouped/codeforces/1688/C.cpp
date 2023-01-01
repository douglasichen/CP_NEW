#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector<int> F('z'+1);
		string S;
		for (int i=0; i<(N<<1); i++) {
			cin>>S;
			for (char i : S) F[i]++;
		}
		cin>>S;
		for (char i : S) F[i]++;
		for (char c='a'; c<='z'; c++) {
			if (F[c]&1) {
				cout << c << endl;
				break;	
			}
		}
	}
}