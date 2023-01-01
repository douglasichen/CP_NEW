#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
    vector<int> V(N*2);
    for (int &i : V) cin>>i;
    sort(V.begin(), V.end());
    int ans=0;
	for (int i=0; i<N; i++) ans-=V[i];
	for (int i=N; i<2*N; i++) ans+=V[i];
	cout << ans << endl;
}