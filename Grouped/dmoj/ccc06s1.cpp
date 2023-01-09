#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string A,B; cin>>A>>B;
	int X; cin>>X;
	string S;
	while (X--) {
		cin>>S;
		int N=S.size(), gd=1;
		for (int i=0; i<N; i++) {
			if (isupper(S[i])) {
				if (!(isupper(A[i*2]) || isupper(A[i*2+1])
					|| isupper(B[i*2]) || isupper(B[i*2+1])))
						gd=0;
			}
			else {
				if (!(islower(A[i*2]) && islower(B[i*2]) || islower(A[i*2+1])
					 && islower(B[i*2+1])))
						gd=0;
			}
		}
		cout << (gd ? "Possible baby." : "Not their baby!") << endl;
	}
}