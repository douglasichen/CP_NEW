#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> B(N+1), O(N+2), A(N+1), C(N+1,1);
	for (int i=1; i<=N; i++) cin>>B[i], O[i]=i;
	auto cmp=[&](int a, int b){
		if (B[a]==B[b]) return a<b;
		return B[a]<B[b];
	};
	sort(O.begin()+1, O.end()-1, cmp);
	O[0]=O[1];

	bool bad=0;
	vector<int> last(N+1), fix;
	for (int e=1,i; e<=N+1; e++) {
		int cntA=B[O[e]], cntB=B[O[e-1]];
		if (cntA!=cntB) { // new numbers
			if (fix.size()%cntB==0) { 
				for (int o=0; o<fix.size(); o++)
					if (o%cntB==0) A[fix[o]]=fix[o+cntB-1];
					else A[fix[o]]=fix[o-1];
			}
			else {
				bad=1;
				break;
			}
			fix.clear();
		}

		i=O[e];
		if (B[i]==1) A[i]=i; // if it is a 1, only only option: i
		else if (last[B[i]-1]) A[i]=last[B[i]-1];
		else fix.push_back(i);
		last[B[i]]=i;
	}

	if (bad) cout << -1 << endl;
	else {
		for (int i=1; i<=N; i++) cout << A[i] << ' '; cout << endl;
	}


}