#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s; cin>>s;
	vector<vector<bool>> can(10,vector<bool>(10));
	vector<int> v={1,2,3,4,5,6,7,8,9,0};
	for (int i=1; i<10; i++) can[v[i]][v[i-1]]=1, can[v[i-1]][v[i]]=1;
	for (int i=1; i<s.size(); i++) {
		int b=s[i]-'0', a=s[i-1]-'0';
		if (!can[a][b]) {
			cout << "INVALID" << endl;
			return 0;
		}
	}
	cout << "VALID" << endl;
}