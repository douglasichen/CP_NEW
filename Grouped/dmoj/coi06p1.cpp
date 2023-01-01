#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	long long ans=0;
	int N; cin>>N;
	vector<int> S;
	for (int i=0, e; i<N; i++) {
		cin>>e;

		int L=0, R=S.size()-1;
		while (L<R) {
			int M=L+R+1>>1;
			if (S[M]<=e) R=M-1;
			else L=M;
		}
		ans+=S.size()-L;

		while (S.size() && S.back()<e) S.pop_back();
		S.push_back(e);
	}
	cout << ans << endl;
}