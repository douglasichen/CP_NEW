#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    ll N,M,ans=LLONG_MAX,sm=0; cin>>N>>M;
    vector<ll> V(N);
    for (ll &i : V) cin>>i;
    for (int a=0, b=0; a<N; a++) {
        sm+=V[a];
        while (b<a && sm-V[b]>=M) {
            sm-=V[b];
            b++;
        }
        if (sm>=M) ans=min(ans,(ll)(a-b+1));
    }
    cout << (ans==LLONG_MAX ? -1 : ans) << endl;
}