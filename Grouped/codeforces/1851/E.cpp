#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=2e5;

ll co[MAXN+1],N,K,T,ans[MAXN+1];
bool done[MAXN+1];
vector<int> gr[MAXN+1];

ll solve(int p) {
    if (SZ(gr[p])==0 && !done[p]) done[p]=1, ans[p]=co[p];
    if (done[p]) return ans[p];
    for (int i : gr[p]) ans[p]+=solve(i);
    ans[p]=min(ans[p], co[p]);
    done[p]=1;
    return ans[p];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while (T--) {
        cin>>N>>K;

        for (int i=1; i<=N; i++) gr[i].clear();

        ms(ans,0);
        ms(done,0);

        for (int i=1; i<=N; i++) cin>>co[i];
        for (int i=1,a; i<=K; i++) cin>>a, done[a]=1; 
        for (int i=1; i<=N; i++) {
            int M; cin>>M;
            for (int m=0,a; m<M; m++) {
                cin>>a;
                gr[i].push_back(a);
            }
        }
        for (int i=1; i<=N; i++) {
            ans[i]=solve(i);
            cout << ans[i] <<' ';
        }
        cout << endl;
    }
}