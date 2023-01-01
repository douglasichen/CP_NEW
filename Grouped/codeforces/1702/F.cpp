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
		map<int,int> M;
		vector<int> A(N);
		for (int i=0; i<N; i++) {
			cin>>A[i];
			while ((A[i]&1)==0) A[i]>>=1;
		}

		for (int i=0, e; i<N; i++) {
			cin>>e;
			while ((e&1)==0) e>>=1;
			M[e]++;
			// cout << e << ' ';
		}
		// cout << endl;
		sort(A.begin(), A.end(), greater<int>());
		// for (int i : A) cout << i << ' '; 
		// cout << endl;

		bool ans=1;
		for (int a : A) {
			int e=a;
			bool gd=0;
			for (int i=0; a<=1e9; i++, a<<=1) {
				auto it=M.lower_bound(a);
				if (it!=M.end()) {
					pair<int,int> p=*it;
					if (p.second && p.first<a+(1<<i)) {
						gd=1;
						it->second=p.second-1;
						// cout << e << " " << p.first << endl;
						if ((it->second)==0) M.erase(it);
					}
				}
				if (gd) break;
			}
			if (!gd) {
				ans=0;
				break;
			}
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
}