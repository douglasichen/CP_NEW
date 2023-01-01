#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
ofstream out;

void printDP(vector<vector<int>> dp) {
	for (int y=0; y<dp.size(); y++)
		for (int x=0; x<dp[0].size(); x++)
			out << dp[y][x] << (x==dp[0].size()-1 ? '\n' : ' ');
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	
	out.open ("out.txt");
	// myfile << "Writing this to a file.\n";
	
	int N,C; cin>>N>>C;
	vector<int> W(N+1);
	for (int i=1; i<=N; i++) cin>>W[i];
	vector<bool> used(N+1);
	for (int bin=1; bin<=1; bin++) {
		bool gd=0;
		vector<vector<int>> dp(N+1, vector<int>(C+1));
		vector<vector<pair<int,int>>> from(N+1, vector<pair<int,int>>(C+1));
		for (int i=1; i<=N; i++) {
			for (int c=1; c<=C; c++) {
				pair<int,int> best={0,0}; // i, cnt
				for (int k=1; k<=N; k++) {
					// max (dp[i-k][c-W[i]]+1, dp[i-1][c], dp[i][c]);
					vector<int> node={i-k, c-W[i]};
					if (c-W[i]>=0) {
						int cnt=dp[node[0]][node[1]]+1;
						dp[i][c]=max(dp[i][c], cnt);

						if (cnt>best.second) best={i-k, cnt};
					}
				}
				if (best.first && best.second) {
					from[i][c]={best.first, c-W[i]};
				}
			}
		}
		printDP(dp);
		// for (int c=C; c; c--) out << dp[N][c]

		break;

		// for (int c=C; c; c--) {
		// 	if (dp[N][c]) {

		// 		break;
		// 	}
		// }
		
		// if (gd) {
		// 	cout << bin << endl;
		// 	break;
		// }
	}
	

	out.close();
}