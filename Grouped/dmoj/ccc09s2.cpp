#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, L; cin>>R>>L;
	vector<bitset<8>> V(R);
	for (int y=0; y<R; y++)
		for (int i=0,a; i<L; i++)
			cin>>a, V[y][i]=a;
	
	int mxComb=1<<L;
	int ans=0;
	bitset<8> comb=0;
	for (int c=0; c<mxComb; c++) {
		comb=c;
		bool gd=0;
		for (int r=R-1; r>=0; r--) {
			for (int i=0; i<L; i++)
				comb[i]=V[r][i]^comb[i];
			if (comb==0) gd=1;
		}
		if (gd) ans++;
	}
	cout << ans << endl;
}