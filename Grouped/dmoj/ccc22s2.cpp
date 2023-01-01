#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair

pair<string,string> A[100001], B[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int X,Y,G; cin>>X;
	for (int i=0; i<X; i++) cin>>A[i].first>>A[i].second;
	cin>>Y;
	for (int i=0; i<Y; i++) cin>>B[i].first>>B[i].second;
	
	unordered_map<string, bool> UM;
	cin>>G;
	for (int g=0; g<G; g++) {
		string a,b,c; cin>>a>>b>>c;
		UM[a+" "+b]=1;
		// UM[b+" "+a]=1;
		UM[a+" "+c]=1;
		// UM[c+" "+a]=1;
		UM[b+" "+c]=1;
		// UM[c+" "+b]=1;
	}

	int ans=0;
	for (int x=0; x<X; x++)
		if (!UM[A[x].first+" "+A[x].second] && !UM[A[x].second+" "+A[x].first])
			ans++;
	for (int y=0; y<Y; y++)
		if (UM[B[y].first+" "+B[y].second] || UM[B[y].second+" "+B[y].first])
			ans++;
	cout << ans << endl;
}