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
		unordered_map<string,vector<pair<int,int>>> M;
		int N; cin>>N;
		vector<string> V(N+1);
		string S;
		for (int i=1; i<=N; i++) {
			cin>>S; V[i]=S;
			reverse(S.begin(),S.end());
			M[S].push_back({i,S.size()});
			if (S.size()==3) S.erase(0,1), M[S].push_back({i,3});
		}
		bool ans=0;
		for (int i=1; i<=N; i++) {
			string S=V[i], S2=S; S2.erase(0,1);
			for (pair<int,int> p : M[S]) if (p.first<=i) ans=1;
			if (S.size()==3) for (pair<int,int> p : M[S2]) if (p.first<=i && p.second==2) ans=1;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}	
}