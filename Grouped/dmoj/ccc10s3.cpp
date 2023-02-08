#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int N=1000000;
int ar[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ms(ar,0);

	int H; cin>>H;
	for (int i=0; i<H; i++) cin>>ar[i];
	sort(ar,ar+H);

	int ans=N;
	int K; cin>>K;
	for (int start=0; start<H; start++) {
		int L=0, R=N;
		while (L<R) {
			int len=L+R>>1, last=-1, first=-1, k=0;
			for (int i=start; i<H+start; i++) {
				int dist=min(abs(ar[i%H]-last), N-abs(ar[i%H]-last));
				if (last==-1 || dist>len) {
					last=(ar[i%H]+len)%N;
					if (first==-1) first=last;
					k++;
				}
			}
			if (k<=K) R=len;
			else L=len+1;
		}
		ans=min(ans,R);
	}

	cout << ans << endl;
}