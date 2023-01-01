#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	for (int i=N; i>=1; i--) cout << i << ' '; cout << endl;
	vector<int> ans={1};
	for (int i=3; i<=N; i++) ans.push_back(i);
	if (N>1) ans.push_back(2);
	for (int i : ans) cout << i << ' ';
	cout << endl;
}