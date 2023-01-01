#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N, sm=0; cin>>N;
		vector<int> V(N+1);
		for (int i=1; i<=N; i++) cin>>V[i], sm+=V[i];

		vector<vector<int>> ans;
		if (sm) {
			if (sm<0) {
				sm=-sm;
				for (int &i : V) i=-i;
			}
			if ((sm&1)==0) {
				sm>>=1;
				int a=0, b=0;
				for (int i=1; i<=N; i++) {
					if (i&1) a+=(V[i]==1);
					else b+=(V[i]==1);
				}
				if (max(a,b)>=sm) {
					int x=1, y=2;
					if (a>b) x=2, y=3, ans.push_back({1,1});
					for (; y<=N && sm; y+=2) {
						if (V[y]==-1) {
							ans.push_back({x,y-1});
							ans.push_back({y,y});
							x=y+1;
						}
						else if (V[y]==1) sm--;
						if (sm==0) {
							ans.push_back({x,y});
						}
					}
					for (int i=ans.back()[1]+1; i<=N; i++)
						ans.push_back({i,i});
				}
			}
		}
		else {
			for (int i=1; i<=N; i++) 
				ans.push_back({i,i});
		}
		if (ans.size()==0) cout << -1 << endl;
		else {
			cout << ans.size() << endl;
			for (vector<int> &i : ans)
				cout << i[0] << ' ' << i[1] << endl;
		}
	}	
}