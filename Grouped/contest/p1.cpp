#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; cin>>S;
	string h="HONI";
	int at=0;

	int ans=0;
	for (char c : S) {
		if (c==h[at%4]) {
			at++;
			if (at%4==0) ans++;
		}
	}
	cout << ans << endl;
}