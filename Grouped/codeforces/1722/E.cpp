#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; cin>>T;
    while (T--) {
        int N,Q; cin>>N>>Q;
        vector<vector<ll>> V(1001, vector<ll>(1001));
        for (int i=0, h, w; i<N; i++) cin>>h>>w, V[h][w]+=h*w;
        for (int h=1; h<1001; h++) for (int w=1; w<1001; w++) V[h][w]+=V[h][w-1];
        while (Q--) {
            int a,b,c,d; cin>>a>>b>>c>>d;
            ll ans=0;
            for (int h=a+1; h<c && b<d; h++) ans+=V[h][d-1]-V[h][b];
            cout << ans << endl;
        }

    }
}