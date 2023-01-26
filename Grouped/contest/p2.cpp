#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=201;
int ar[MAXN];
map<int,int> fr;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;

	int ans=0;
	for (int i=0; i<N; i++) cin>>ar[i], fr[ar[i]]++, ans=max(ans,fr[ar[i]]);

	for (int a=0; a<N; a++) {
		for (int b=a; b<N; b++) {
			fr[ar[b]]--;
			ar[b]+=K;
			fr[ar[b]]++;
			
			for (pair<int,int> p : fr) ans=max(ans,p.second);
		}
	}
	cout << ans << endl;
}