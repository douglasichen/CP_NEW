#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N, L, S; cin>>N>>L>>S;
	vector<vector<int>> V;
	for (int i=0,a,b,s; i<N; i++) cin>>a>>b>>s, V.push_back({a,s}), V.push_back({b+1,-s});
	sort(V.begin(),V.end());
	vector<vector<int>> tmp={V[0]};
	for (int i=1; i<V.size(); i++) {
		if (tmp.back()[0]==V[i][0]) tmp.back()[1]+=V[i][1];
		else tmp.push_back(V[i]);
	}
	swap(V,tmp);
	int K=V.size(), ans=L;
	for (int i=0; i<K-1; i++) {
		V[i][1]+=(i ? V[i-1][1] : 0);
		if (V[i][1]>=S) ans-=V[i+1][0]-V[i][0];
	}
	cout << ans << endl;
	
}