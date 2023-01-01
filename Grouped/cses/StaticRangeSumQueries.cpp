#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N,Q; cin>>N>>Q;
    int A[N+1];
    for (int i=1; i<=N; i++) cin>>A[i];   
    long long psa[N+1];
    for (int i=1; i<=N; i++) psa[i]=psa[i-1]+A[i];
    for (int q=0; q<Q; q++) {
        int a,b; cin>>a>>b;
        cout << psa[b]-psa[a-1] << endl;
    }
}
