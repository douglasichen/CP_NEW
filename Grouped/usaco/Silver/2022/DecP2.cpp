#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1e5+1, MAXA=5e6+1;
int ar[MAXN], bp[MAXA], turns[MAXN];
bool win[MAXN], dp[MAXA], isP[MAXA];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);
	fill(isP,isP+MAXA,1);

	for (int i=2; i<MAXA; i++) {
		for (int at=i+i; at<MAXA; at+=i) isP[at]=0;
	}
	for (int i=1; i<MAXA; i++) {
		bp[i]=bp[i-1];
		if (isP[i]) bp[i]=i;
	}
	
	for (int i=1; i<MAXA; i++) dp[i]=dp[i-bp[i]]^1;

	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		ms(turns,0);
		for (int i=0; i<N; i++) {
			cin>>ar[i], win[i]=dp[ar[i]];
			int at=ar[i];
			while (at) {
				at-=bp[at];
				turns[i]++;
			}
		}
		int mn=*min_element(turns,turns+N);
		for (int i=0; i<N; i++) turns[i]-=mn;

		bool ans=0;
		for (int i=0; i<N; i++) {
			if (turns[i]==0) {
				ans=win[i];
				break;
			}
		}
		cout << (ans ? "Farmer John" : "Farmer Nhoj") << endl;
		
	}
}