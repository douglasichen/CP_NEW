#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SZ(a) int(a.size())
#define endl '\n'
#define ms(a,b) memset(a,b,sizeof(a))

const int MAXN=2e5;
int A[MAXN], B[MAXN];

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin>>N;
    ll ans=0;
    for (int i=0; i<N; i++) cin>>A[i], ans+=A[i];
    for (int i=0; i<N; i++) cin>>B[i], ans+=B[i];
    ans*=3;
    for (int i=1; i<N; i++) {
        if (A[i] && A[i-1]) ans-=2;
        if (B[i] && B[i-1]) ans-=2;
    }
    for (int i=0; i<N; i+=2) if (A[i] && B[i]) ans-=2;
    cout << ans << endl;
}