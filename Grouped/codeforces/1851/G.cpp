#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ms(a,x) memset(a,x,sizeof(a))
#define SZ(x) x.size()

const int MAXN=2e5+1;

int dsu[MAXN], he[MAXN], qs[MAXN][4], qo[MAXN], ho[MAXN], ans[MAXN];
vector<int> gr[MAXN];

int root(int a) {
    return dsu[a] < 0 ? a : root(dsu[a]);
}

void join(int a, int b) {
    a=root(a), b=root(b);
    if (a==b) return;
    if (dsu[a]>dsu[b]) swap(a,b);
    dsu[a]+=dsu[b];
    dsu[b]=a;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while (T--) {
        int N,M; cin>>N>>M;
        for (int i=1; i<=N; i++) gr[i].clear();
        for (int i=1; i<=N; i++) cin>>he[i];
        for (int i=0,a,b; i<M; i++) cin>>a>>b, gr[a].push_back(b), gr[b].push_back(a);
        int Q; cin>>Q;
        for (int q=0; q<Q; q++) cin>>qs[q][0]>>qs[q][1]>>qs[q][2], qs[q][3]=he[qs[q][0]]+qs[q][2];

        iota(qo,qo+Q,0);
        sort(qo,qo+Q,[](int a, int b) {
            return qs[a][3]<qs[b][3];
        });

        iota(ho,ho+N,1);
        sort(ho,ho+N,[](int a, int b) {
            return he[a]<he[b]; 
        });

        fill(dsu,dsu+N+1,-1);
        ms(ans,0);
        int at=0;
        for (int e=0; e<Q; e++) {
            int q=qo[e];
            while (at<N && he[ho[at]]<=qs[q][3]) {
                for (int child : gr[ho[at]]) {
                    if (he[child]<=qs[q][3]) join(ho[at],child);
                }
                at++;
            }
            if (root(qs[q][0]) == root(qs[q][1])) ans[q]=1;
        }
        for (int i=0; i<Q; i++) cout << (ans[i] ? "YES" : "NO") << endl;


    }
}

/*
7 7
1 5 3 4 2 4 1
1 4
4 3
3 6
3 2
2 5
5 6
5 7
1
6 2 0

*/