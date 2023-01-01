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
		int N,K; cin>>N>>K;
		vector<int> V(N);
		multiset<vector<int>> MS;
		for (int i=0; i<N; i++) cin>>V[i], MS.emplace(vector<int>{V[i]%K, i});
		long long sm=0;
		vector<bool> done(N);
		for (int i=0; i<N; i++) {
			if (done[i]) continue;
			done[i]=1;

			int r1=V[i]%K;
			MS.erase(MS.lower_bound(vector<int>{r1,i}));
			
			vector<int> use;
			int left=K-r1;
			auto a=MS.lower_bound(vector<int>{left,i});
			if (a==MS.end()) a--;
			if ((*a)[0]==left) use=(*a), MS.erase(a);
			else {
				auto b=MS.lower_bound(vector<int>{0,0});
				int rA=r1+(*a)[0], rB=r1+(*b)[0]; rA%=K, rB%=K;
				if (rA<=rB) use=(*a), MS.erase(a);
				else use=(*b), MS.erase(b);
			}
			done[use[1]]=1;
			sm+=(V[i]+V[use[1]])/K;
		}
		cout << sm << endl;
	}
}