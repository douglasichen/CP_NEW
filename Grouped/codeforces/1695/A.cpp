#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin>>T;
	for (int o=0; o<T; o++) {
		int N,M; cin>>N>>M;
		vector<vector<int>> V(N+1,vector<int>(M+1));
		vector<int> mx={0,0,(int)(-1e9-1)};
		for (int y=1; y<=N; y++)
			for (int x=1; x<=M; x++)
				cin>>V[y][x], mx=(V[y][x]>mx[2] ? vector<int>{y,x,V[y][x]} : mx);
		int a=mx[0]*mx[1], b=(N-mx[0]+1)*mx[1], c=mx[0]*(M-mx[1]+1), d=(N-mx[0]+1)*(M-mx[1]+1);
		int ans=max(a,max(b,max(c,d)));
		cout << ans << endl;
	}
}