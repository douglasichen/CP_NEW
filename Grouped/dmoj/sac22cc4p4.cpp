#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


int N,B,T;
vector<int> V;
ll cnt(int t) {
    if (t==-1) return 0;
    ll ret=0;
    multiset<int> S;
    for (int r=0, l=0; r<N; r++) {
        S.insert(V[r]);
        int dif=(*S.rbegin())-(*S.begin());
        while (l<r && !S.empty() && dif>t)
            S.erase(S.find(V[l])), 
            dif=(*S.rbegin())-(*S.begin()), 
            l++;
        ll len=r-l+1;
        ret+=len;
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>B>>T;
    V.assign(N,0);
    for (int &i : V) cin>>i;
    cout << cnt(T)-cnt(B-1) << endl;
}
