#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		map<string,vector<int>> stock;
		for (int n=0; n<N; n++) {
			int M; cin>>M;
			for (int m=0; m<M; m++) {
				string s; int a,b; cin>>s>>a>>b;
				while (b--) stock[s].push_back(a);
			}
		}
		
		ll ans=0;
		int K; cin>>K;
		for (int k=0; k<K; k++) {
			string s; int a; cin>>s>>a;
			sort(stock[s].begin(), stock[s].end(), greater<int>());
			while (a--) {
				ans+=stock[s].back(); stock[s].pop_back();
			}

		}
		cout << ans << endl;
	}
}