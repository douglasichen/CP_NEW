#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	while (T--) {

		// set
		int N,M,ans=1; cin>>N>>M;
		vector<pair<string,char>> V(M);
		for (int i=0; i<M; i++) cin>>V[i].first>>V[i].second;
		vector<vector<char>> op={{'0','0'},{'0','1'},{'1','0'},{'1','1'}};
		
		// GD order
		vector<int> row(M), col(N);
		for (int i=0; i<N; i++) {
			bool gd=0;
			for (int a=0; a<N; a++) {
				if (col[a]) continue;
				gd=0;
				for (int b=0; b<4; b++) {
					gd=1;
					for (int c=0; c<M; c++) {
						if (!row[c])
							if (V[c].first[a]==op[b][0] && V[c].second!=op[b][1])
								gd=0;
					}
					if (gd) {
						for (int c=0; c<M; c++)
							if (V[c].first[a]==op[b][0] && V[c].second==op[b][1])
								row[c]=1;

						col[a]=1;
						break;
					}
				}
				if (gd) {
					break;
				}
			}
			if (!gd) {
				ans=0;
				break;
			}
		}
		for (int i=0; i<N; i++) {
			set<pair<char,char>> S;
			for (int c=0; c<M; c++)
				if (!row[c])
					S.insert({V[c].first[i], V[c].second});
			if (S.size()>1) ans=0;
		}

		cout << (ans ? "OK" : "LIE") << endl;
	}
}