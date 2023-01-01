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
		vector<int> V(N);
		string s;
		for (int i=0; i<N; i++) cin>>s, V[i]=s.back()-'0';
		vector<vector<bool>> has(24, vector<bool>(4)); // bool mask of sums, bool mask of can use i elements to get there
		for (int i=0; i<N; i++) {
			vector<vector<bool>> oHas=has;
			for (int el=0; el<=23; el++) {
				for (int cnt=1; cnt<=2; cnt++) {
					if (oHas[el][cnt]) {
						int sm=el+V[i];
						if (sm<=23) has[sm][cnt+1]=1;
					}
				}
			}
			has[V[i]][1]=1;
		}
		if (has[3][3] || has[13][3] || has[23][3]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
