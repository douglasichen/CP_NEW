#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin>>N;
    vector<int> V(N);
    for (int i=0; i<N; i++) cin>>V[i];
    sort(V.begin(), V.end());
    V.push_back(int(1e9));
        
    int Q; cin>>Q;
    while (Q--) {
        int a,b; cin>>a>>b;
        cout << (upper_bound(V.begin(), V.end(), b)-1-upper_bound(V.begin(), V.end(), a-1)) << '\n';
    }
}