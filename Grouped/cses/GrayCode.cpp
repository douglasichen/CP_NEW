#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    int N=1<<n;
    for (int i=0; i<N; i++) {
        int k=i^(i>>1);
        for (int l=0; l<n; l++, k>>=1)
            cout << (k&1);
        cout << endl;
    }

}
