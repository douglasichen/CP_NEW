#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> V(N);
	for (int i=0; i<N; i++) cin>>V[i];
	vector<int> left(N,1), right(N,1);
	for (int a=N-2; a>=0; a--) {
		for (int b=a+1; b<N; b++) {
			if (V[a]>V[b])
				right[a]=max(right[a], 1+right[b]);
		}
	}
	for (int a=1; a<N; a++) {
		for (int b=0; b<a; b++) {
			if (V[a]>V[b])
				left[a]=max(left[a], 1+left[b]);
		}
	}
	int ans=0;

	for (int a=0; a<N; a++) {
		for (int b=a; b<N; b++) {
			if (V[a]!=V[b]) {
				ans=max(ans,left[a]+right[b]-(a==b));
			}
		}
	}
	cout << N-ans << endl;
}