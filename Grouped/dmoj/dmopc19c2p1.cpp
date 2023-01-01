#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    int N; cin>>N;
    vector<int> V(N);
    for (int &i : V) cin>>i;
	sort(V.begin(), V.end());
	float a=V[0], b=V[N-1], c=((N/2)&1 ? V[N/4] : (V[N/4]+V[N/4-1])/2.0), 
	d=(N&1 ? V[N/2] : (V[N/2]+V[N/2-1])/2.0), 
	e=((N/2)&1 ? V[N-1-N/4] : (V[N-N/4]+V[N-N/4-1])/2.0);
	cout << setprecision(10) << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
}