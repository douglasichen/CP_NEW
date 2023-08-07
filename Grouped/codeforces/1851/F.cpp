#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=2e5;
int ar[MAXN], br[MAXN], cr[MAXN], ir[MAXN], N, K, I=-1,J=-1,X=0;
vector<int> gd;

void gengd() {
    iota(ir,ir+N,0);
    sort(ir,ir+N, [](int a, int b) {
        return br[a]<br[b];
    });

    gd.clear();
    gd.push_back(ir[0]);
    for (int i=1, cnt=1; i<N; i++) {
        if (br[ir[i]]==br[ir[i-1]]) gd.push_back(ir[i]), cnt++;
        else {
            if (cnt==1) gd.pop_back();
            if (i<N-1) gd.push_back(ir[i]), cnt=1;
        }
    }
}

void calcans() {
    I=gd[0], J=gd[1];
    for (int e=0; e<K; e++) {
        if ((cr[I]>>e&1)==0 && (cr[J]>>e&1)==0) X+=(1<<e);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while (T--) {
        cin>>N>>K;
        I=-1,J=-1,X=0;
        for (int i=0; i<N; i++) cin>>ar[i], cr[i]=ar[i];

        for (int at=K-1; at>=0; at--) {
            for (int i=0; i<N; i++) br[i]=(ar[i]>>at);
            gengd();

            if (SZ(gd)==2 || SZ(gd)>2 && at==0) {
                calcans();
                break;
            }
            if (!SZ(gd)) for (int i=0; i<N; i++) ar[i]|=(1<<at);
        }
        if (I==-1) {
            for (int i=0; i<N; i++) br[i]=ar[i];
            gengd();
            if (SZ(gd)) calcans();
            else I=0, J=1, X=0;
        }

        cout << I+1 << ' ' << J+1 << ' ' << X << endl;
    }
}