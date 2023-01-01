#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while (T--) {
        long long ans=0;
        int N; cin>>N;
        vector<int> V(N);
        for (int i=0; i<N; i++) cin>>V[i];
        int cut=2*V[0]-1;
        for (int i=1; i<N; i++) {
            if (cut<=V[i]) {
                ans+=V[i]/cut+(V[i]%cut!=0)-1;
            }
        }
        cout << ans << endl;
    }   
}
