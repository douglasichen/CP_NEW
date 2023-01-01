#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M,A,B; cin>>N>>M>>A>>B;
	int at=A, lastUnk=0;
	vector<vector<int>> V(M,vector<int>(2));
	for (int i=0; i<M; i++) {
		int x,y; cin>>x;
		if (x==-1) {
			lastUnk=i;
			continue;
		};
		cin>>y;
		V[i]={x,y};
	}
	for (int i=0; i<lastUnk; i++) {
		vector<int> sw=V[i];
		if (sw[0]) { // not unk
			if (at==sw[0]) at=sw[1];
			else if (at==sw[1]) at=sw[0];
		}
		else { //is unk
			if (V[i+1][0]) { //if the next one is not unkown
				if (at!=V[i+1][0]) V[i]={at,V[i+1][0]}, at=V[i+1][0];
				else V[i]={at,V[i+1][1]}, at=V[i+1][1];
			}
			else {
				V[i]={1,2};
				if (at==1) V[i][0]=3;
				if (at==2) V[i][1]=3;
			}
		}
	}
	int be=B;
	for (int i=M-1; i>lastUnk; i--) {
		vector<int> sw=V[i];
		if (be==sw[0]) be=sw[1];
		else if (be==sw[1]) be=sw[0];
	}
	if (at==be) {
		V[lastUnk]={1,2};
		if (at==1) V[lastUnk][0]=3;
		if (at==2) V[lastUnk][1]=3;
	}
	else {
		V[lastUnk]={at,be};
	}

	for (int i=0; i<M; i++) cout << V[i][0] << ' ' << V[i][1] << endl;
}