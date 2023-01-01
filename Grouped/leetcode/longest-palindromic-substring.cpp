#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s; cin>>s;
	int N=s.size();
	vector<int> ans={0,1};
	vector<vector<string>> V(N);
	for (int i=N-1; i>=0; i--) {
		string sub="";
		for (int j=i; j>=0; j--) {
			sub+=s[j];
			V[j].push_back(sub);
		}
	}
	for (vector<string> &v : V)
		sort(v.begin(), v.end());
	for (int i=0; i<N; i++) {
		string sub="";
		for (int j=i; j<N; j++) {
			sub+=s[j];
			for (int o=0; o<2; o++) {
				if (j+o>=N) break;
				if (binary_search(V[j+o].begin(), V[j+o].end(), sub)) {
					int sz=(j-i+1)*2+(o-1);
					if (sz>ans[1]-ans[0])
						ans[0]=i,
						ans[1]=i+sz;
				}
			}
		}
	}
	string ret="";
	for (int i=ans[0]; i<ans[1]; i++) ret+=s[i];
	cout << ret << endl;
}