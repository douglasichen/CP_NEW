#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	vector<int> A(N+1), B(N+1), V(N+2), dif(N+2);
	for (int i=1; i<=N; i++) cin>>A[i];
	for (int i=1; i<=N; i++) cin>>B[i];
	for (int i=1; i<=N; i++) V[i]=A[i]-B[i];
	for (int i=1; i<=N+1; i++) dif[i]=V[i]-V[i-1];

	long long ans=0;
	for (int &i : dif) ans+=abs(i);
	ans/=2;
	cout << ans << endl;
}