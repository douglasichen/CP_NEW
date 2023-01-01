#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N;
vector<int> ans,V;
void solve(int a, int b, int neg, int twos) {
	if (neg) {
		int a2=0, b2=0, x=0, y=0;
		for (int i=a; i<b; i++) {
			a2+=abs(V[i])==2;
			x=i;
			if (V[i]<0) break;
		}
		for (int i=b-1; i>=a; i--) {
			b2+=abs(V[i])==2;
			y=i;
			if (V[i]<0) break;
		}
		if (a2<b2) a=x+1, twos-=a2;
		else b=y, twos-=b2;
	}
	if (twos>ans[0]) ans={twos,a,N-b};
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		cin>>N;
		ans={0,0,N};
		V.assign(N,0);
		for (int &i : V) cin>>i;
		for (int b=0, a=0, neg=0, twos=0; b<=N; b++) {
			while (a<N && V[a]==0) a++;
			if (b<N) {
				neg^=(V[b]<0);
				twos+=(abs(V[b])==2);
			}
			if (a<b && b<N && V[a] && !V[b] || a<b && b==N && V[a]) {
				solve(a,b,neg,twos);
				neg=0, twos=0;
				a=b+1;
			}
			
		}
		cout << ans[1] << ' ' << ans[2] << endl;
	}
}