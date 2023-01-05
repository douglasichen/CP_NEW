#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int TSZ=1<<20;
int preSmTree[TSZ*2], lazy[TSZ*2], ar[TSZ], psa[TSZ], ord[TSZ];
pair<int,int> qs[TSZ];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(preSmTree, 0, sizeof(preSmTree));
    memset(lazy, 0, sizeof(preSmTree));
    
    int N,Q; cin>>N>>Q;
    // take input
    for (int i=0; i<N; i++) cin>>ar[i], psa[i]=(i ? psa[i-1] : 0)+ar[i];

    // sort queries by decreasing l
    for (int i=0; i<Q; i++) cin>>qs[i].first>>qs[i].second, qs[i].first--;
    
    iota(ord, ord+N, 0);

    auto srt=[&](int a, int b) {
        return qs[a].first>qs[b].first;
    };
    sort(ord, ord+N, srt);
    

    // ans=sum of maxPrefixes from l to r - sum of elements from l to r
    ll ans=0;
    int at=N-1, st[TSZ], head=0;
    for (int i=0; i<Q; i++) {
        int ind=ord[i];
        
        ans=0;
        for (; at>qs[ind].first; at--) {
            if (head==0 || st[head-1]>ar[at]) head++;
            st[head-1]=at;
        }
        // the next biggest one is st[head-2];
        if (head-1)

        cout << ans << endl;
    }
}
