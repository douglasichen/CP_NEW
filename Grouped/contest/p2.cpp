#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) int(x.size())

const int MAXN=1e6+1, MAXA=4e6+2, P=2e6;
int A[MAXN], B[MAXN], X[MAXN], Y[MAXN];
vector<bool> ma[MAXA];
bitset<MAXA> vis;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N,K; cin>>N>>K;
    vector<int> op;
    for (int i=0,a; i<N; i++) {
        cin>>a;
        ma[a+P].push_back(1);
        if (!vis[a+P]) op.push_back(a+P), vis[a+P]=1;
        if (K) {
            ma[a+K+P].push_back(0);
            if (!vis[a+K+P])
                op.push_back(a+K+P),
                vis[a+K+P]=1;
        }
    }

    int ans=0;
    for (int e : op) {
        for (int i=1; i<=SZ(ma[e]); i++) {
            A[i]=A[i-1]+(ma[e][i-1]==0);
            B[i]=B[i-1]+(ma[e][i-1]==1);
        }
        for (int i=0; i<=SZ(ma[e]); i++) X[i]=A[i]-B[i], Y[i]=B[i]-A[i];

        for (int i=1; i<=SZ(ma[e]); i++) Y[i]=max(Y[i], Y[i-1]);
        for (int i=SZ(ma[e])-1; i>=0; i--) X[i]=max(X[i], X[i+1]);
        for (int i=0; i<SZ(ma[e]); i++) ans=max(ans, Y[i]+X[i]+B[SZ(ma[e])]);
    }
    cout << ans << endl;
}