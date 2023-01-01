#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
 
void solve() {
 
}
 
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int T,N; cin>>T;
	while (T--) {
		int N; cin>>N;
		// bool ans=1;
		string A, B; cin>>A>>B;
		int b1=0, b2=0;
		for (int i=0; i<N; i++) b1+=A[i]=='b', b2+=B[i]=='b';
		bool ans=b1==b2;


		int i1, i2;
		for (i1=0, i2=0; ans && i1<N; i1++) {
			if (A[i1]=='b') continue;
			while (i2<N && B[i2]=='b') i2++;
			if (i2==N) {
				ans=0;
				break;
			}
			if (A[i1]!=B[i2] || (A[i1]=='a' && i1>i2) || (A[i1]=='c' && i1<i2)) {
				ans=0;
				break;
			}
			i2++;
		}
		// for (int i=0; i<N; i++) {
		// 	if (pA1[i]<pA2[i] || pC1[i]>pC2[i]) {
		// 		ans=0;
		// 		break;
		// 	}
		// }
 
 
		cout << (ans ? "YES" : "NO") << endl;
	}
}