#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

int N;

bool lss(vector<int> &A, vector<int> &B) {
	for (int i=0; i<N; i++) {
		if (A[i]<B[i]) return 1;
		if (A[i]>B[i]) return 0;
	}
	return 1;
}

vector<int> f(vector<int> &A) {
	vector<int> ans;
	int pos;
	for (int i=0; i<N; i++) {
		if (A[i]==1) {
			pos=i;
			break;
		}
	}
	for (int i=pos; i<N; i++) ans.push_back(A[i]);
	for (int i=0; i<pos; i++) ans.push_back(A[i]);
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector<int> V(N);
	int posA, posB;
	for (int i=0; i<N; i++) {
		cin>>V[i];
		if (V[i]==1) posA=i;
	}
	posB=(posA==0 ? N-1 : posA-1);
	for (int i=posA+1, bck=0; ; i++) {
		if (i==N) i=0, bck=1;
		if (bck && i==posA) break;
		int beh=(i==0 ? N-1 : i-1);
		if (V[i]-V[beh]!=1) {
			posB=beh;
			break;
		}
	}
	
	vector<int> M;
	if (posB+1==posA) M=V;
	else {
		if (posA==posB) {
			for (int i=0; i<N; i++) if (V[i]==2) posB=i;
			int a0=(posA==0 ? N-1 : posA-1), a1=(posA==N-1 ? 0 : posA+1);
			int b0=(posB==0 ? N-1 : posB-1), b1=(posB==N-1 ? 0 : posB+1);
			vector<int> A=V, B=V, C=V, D=V, E=V;
			swap(A[posA], A[b0]), swap(B[posA], B[b1]), swap(C[posB], C[a0]), swap(D[posB], D[a1]), swap(E[posA], E[posB]);
			A=f(A), B=f(B), C=f(C), D=f(D), E=f(E);
			vector<vector<int>> R={A,B,C,D,E};
			sort(R.begin(),R.end());
			M=R[0];
		}
		else {
			int posC=0;
			for (int i=0; i<N; i++) {
				if (V[i]==V[posB]+1) {
					posC=i;
					break;
				}
			}
			int go=(posB==N-1 ? 0 : posB+1);
			M=V;
			swap(M[posC], M[go]);
		}
	}

	vector<int> ans;
	int one;
	for (int i=0; i<N; i++) if (M[i]==1) one=i;
	for (int i=one; i<N; i++) ans.push_back(M[i]);
	for (int i=0; i<one; i++) ans.push_back(M[i]);
	for (int i : ans) cout << i << ' '; cout << endl;


}