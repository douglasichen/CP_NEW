#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define uint unsigned int

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin>>N;
    vector<uint> A(N),B(N);
    for (uint &a : A) cin>>a;
    for (uint &b : B) cin>>b;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<uint>());
    long long ans=0;
    for (int i=0; i<N; i++)
        ans+=A[i]*B[i];
    cout << ans << endl;
}
