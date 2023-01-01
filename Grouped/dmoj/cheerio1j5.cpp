#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	map<int,int> M;
	int N; cin>>N;
	vector<int> V(N),A;
	bool ans=0;
	for (int i=0; i<N; i++) {
		cin>>V[i];
		if (i>0) A.push_back(V[i]-V[i-1]), M[A.back()]++;
	}
	if (M.size()>3) ans=0;
	else if (M.size()==1) ans=0;
	else if (M.size()==2) {
		auto it=M.begin();
		vector<int> A={it->first, it->second};
		it++;
		vector<int> B={it->first, it->second};
		if (A[1]<B[1]) swap(A,B);
		if (B[1]>1) ans=0;
		else {
			if (A.back()==B[0] || A.front()==B[0]) ans=1;
			else ans=0;
		}
	}
	else {
		vector<vector<int>> v;
		for (auto const &i : M) {
			v.push_back({i.second, i.first});
		}
		sort(v.begin(),v.end());
		if (v[0][0]>1 || v[1][0]>1) ans=0;
		else {
			for (int i=1; i<N-1; i++) {
				if (A[i]==v[0][1] && A[i-1]==v[1][1] || A[i]==v[1][1] && A[i-1]==v[0][1]) {
					ans=1;
					break;
				}
			}
		}
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}