#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N,K; cin>>N>>K;
	vector<long long> psa(N+1);
	vector<int> f(K);
	for (int i=1,a; i<=N; i++) 
		cin>>a, psa[i]=psa[i-1]+a, f[psa[i]%K]++;
	long long ans=0;
	for (int &i : f)
		ans+=(1LL*i*(i-1)>>1);
	ans+=f[0];
	cout << ans << endl;
}