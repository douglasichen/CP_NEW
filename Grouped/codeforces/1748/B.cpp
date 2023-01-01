#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	while (T--) {
		int N, ans=0; cin>>N;
		vector<int> V(N);
		char c; 
		for (int i=0; i<N; i++) cin>>c, V[i]=c-'0';
		for (int a=0; a<N; a++) {
			vector<int> f(10);
			for (int b=a, d=0; b<min(a+100,N); b++)
				f[V[b]]++, d+=(f[V[b]]==1), ans+=((*max_element(f.begin(), f.end()))<=d);
		}
		cout << ans << endl;
	}	
}