#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    int N; cin>>N;
    vector<int> V(N+2), D(N+2);
	for (int i=1; i<=N; i++) cin>>V[i];
	for (int i=1; i<=N+1; i++) D[i]=abs(V[i]-V[i-1]);
	cout << accumulate(D.begin(), D.end(), 0)/2 << endl;
}