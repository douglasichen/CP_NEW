#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=1e6;
double dp[MAXN];
int ar[MAXN], fr[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(dp,0);
	ms(fr,0);

	int N; cin>>N;
	for (int i=0; i<N; i++) cin>>ar[i];
	
	fr[ar[N-1]]=1;
	for (int i=N-2; i>=0; i--) {
		if (fr[ar[i]]==0 && ar[i]!=ar[0] && ar[i]!=ar[N-1]) {
			dp[ar[i]]=1.0/(N-i);
			for (int k=1; k<=1000; k++) {
				dp[ar[i]]+=1.0*fr[k]/(N-i)*dp[k];
			}
		}
		fr[ar[i]]++;
	}

	double ans=1.0*fr[ar[0]]/N;
	for (int i=1; i<=1000; i++) {
		if (i!=ar[0] && i!=ar[N-1]) {
			ans+=1.0*fr[ar[i]]/N*dp[i];
		}
	}
	if (ar[0]==ar[N-1]) ans=1;
	cout << fixed << setprecision(7) << ans << endl;

}