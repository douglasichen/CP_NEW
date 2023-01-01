#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,M; cin>>N>>M;
	vector<int> A(N), B(M);
	for (int &i : A) cin>>i;
	for (int &i : B) cin>>i;
	if (N>M) swap(N,M), swap(A,B);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	int L=0, R=1e9, ans=INT_MAX;
	while (L<R) {
		int mid=L+R>>1;

		multiset<int> S;
		for (int &i : B) S.insert(i);

		bool gd=1;
		for (int i=0; i<N && !S.empty(); i++) {
			auto b=S.lower_bound(A[i]-mid);
			if (b!=S.end() && abs(A[i]-*b)<=mid) S.erase(b);
			else gd=0;
		}
		if (gd) R=mid, ans=min(ans,mid);
		else L=mid+1;
	}
	if (ans==INT_MAX) cout << N << ' ' << M << endl;
	cout << ans << endl;
}