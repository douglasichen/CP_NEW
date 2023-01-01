#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	
	int N, ans=1; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	sort(V.begin(), V.end());

	for (int i=0; i<N; i++) {
		vector<int> at={i,i};
		vector<bool> stop={0,0};
		for (int t=1; ; t++) {
			int a=at[0], b=at[1];
			while (!stop[a] && a && V[a-1]>=V[at[0]]-t) a--;
			while (!stop[b] && b<N-1 && V[b+1]<=V[at[1]]+t) b++;
			if (a==at[0] && b==at[1]) {
				ans=max(b-a+1, ans);
				break;
			}
			if (a==at[0]) stop[a]=1;
			if (b==at[1]) stop[b]=1;
			at={a,b};
		}
	}
	cout << ans << endl;	
}