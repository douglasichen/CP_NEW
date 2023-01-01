#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
	string S;
	long long ans,N;
	for (int o=0, cnt; o<T; o++) {
		cin>>N>>S;
		ans=N*(N+1)>>1;
		cnt=1;
		for (int i=1; i<N; i++) {
			if (S[i]==S[i-1]) cnt++;
			else cnt=1;
			if (cnt>=2) ans-=i;
		}
		cout << ans << endl;
	}	
}