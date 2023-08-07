#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

int corn[32][2];

bool collide(vector<vector<int>> a, vector<vector<int>> b) {
	int dy0=abs(a[0][1]-a[1][1]), dx0=abs(a[0][0]-a[1][0]),
		dy1=abs(b[0][1]-b[1][1]), dx1=abs(b[0][0]-b[1][0]);
	if (dy0*dx1 == dy1*dx0) return 0;

	vector<int> X={dx0*(b[0][1]*dx1 - b[0][0]*dy1) - dx1*(a[0][1]*dx0 - a[0][0]*dy0), dy0*dx0 - dy1*dx0},
				Y={dy0*X[0] +  Grouped/dmoj/coci19c4p4.cpp};
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a,b,Grouped/dmoj/coci19c4p4.cppc,d; cin>>a>>b>>c>>d;
	int N, ans=0; cin>>N;
	for (int i=0; i<N; i++) {
		int K; cin>>K;
		for (int k=0; k<K; k++) cin>>corn[k][0]>>corn[k][1];
		bool hit=0;
		for (int k=1; !hit && k<=K; k++) {
			if (collide({{corn[k%K][0], corn[k%K][1]}, {corn[k-1][0], corn[k-1][1]}}, {{a,b}, {c,d}}))
				hit=1;
		}
		ans+=hit;
	}
	cout << ans << endl;

}