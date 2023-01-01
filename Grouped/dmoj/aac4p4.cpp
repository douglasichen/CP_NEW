#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,S,F,L,R; cin>>N>>M>>S>>F>>L>>R;

	vector<vector<bool>> ans(N+1, vector<bool>(M+1));
	vector<int> K(M+1);
	for (int i=1; i<=M; i++) cin>>K[i];

	int best=0;
	for (int i=M; i>=2; i--) {
		if (K[i]==F) {
			best=i;
			break;
		}
	}
	int cnt=0;
	if (!best) {
		if (S!=F) cnt=-1;
		else {
			for (int y=1; y<=N && cnt<L; y++) {
				for (int x=1; x<=M && cnt<L; x++) {
					if (y==S) continue;
					ans[y][x]=1;
					cnt++;
				}
			}
			for (int x=1; x<=M && cnt<L; x++) {
				if (K[x]==S) cnt++, ans[S][x]=1;
			}
		}
	}
	else if (R==0) {
		if (S!=F) cnt=-1;
	}
	else {
		for (int y=1; y<=N && cnt+1<L; y++) {
			for (int x=1; x<best && cnt+1<L; x++) {
				ans[y][x]=1;
				cnt++;
			}
		}
		int at=S;
		for (int i=1; i<=M; i++) {
			if (ans[at][i]) at=K[i];
			else break;
		}
		ans[at][best]=1;
		cnt++;

		for (int x=1; x<=M && cnt<L; x++) {
			for (int y=1; y<=N && cnt<L; y++) {
				if (y==F && x>best) continue;
				if (!ans[y][x])
					ans[y][x]=1,
					cnt++;
			}
		}
	}
	if (cnt<L) cnt=-1;

	cout << cnt << endl;
	if (cnt!=-1) {
		for (int y=1; y<=N; y++)
			for (int x=1; x<=M; x++)
				cout << ans[y][x] << (x<M ? ' ' : '\n');
	}
	
}