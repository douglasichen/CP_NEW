#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin>>N>>K;
    long long ans=0;
    vector<long long> A(N), B(N), C(N);
    iota(C.begin(), C.end(), 0);
    for (int i=0; i<N; i++) {
        cin>>A[i]>>B[i];
        B[i]-=A[i];
        ans+=A[i];
    }
    auto cmp=[&](long long &a, long long &b) {return B[a]<B[b];};
    sort(C.begin(), C.end(), cmp);
    for (int i=0; i<K; i++)
        ans+=B[C[i]];
    cout << ans << endl;
}
