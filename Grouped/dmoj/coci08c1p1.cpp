#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define SZ(a) int(a.size())
#define ms(a,b) memset(a,b,sizeof(a))

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int A,B,C; cin>>A>>B>>C;
	cout << max({B-A-1, C-B-1}) << endl;
}