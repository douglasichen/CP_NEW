#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	ll K; cin>>K; K++;
	vector<ll> F;
	for (ll i=2; i*i<=K; i++)
		while (K%i==0) 
			F.push_back(i-1),
			K/=i;
	if (K>1) F.push_back(K-1);

	vector<int> ans;
	for (int i=1; ans.size()<=1e5 && i<=F.size(); i++)
		while (ans.size()<=1e5 && F[i-1]--)
			ans.push_back(i);

	if (ans.size()<=1e5) {
		cout << ans.size() << endl;
		for (int i : ans) cout << i << ' '; cout << endl;
	}
	else cout << "Sad Chris" << endl;
}