#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5;
int X[MAXN], Y[MAXN];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        for (int i=0; i<N; i++) cin>>X[i];
        for (int i=0; i<N; i++) cin>>Y[i];
        int ans=0;
        for (int x=0, y=0; y<N; y++) {
            while (x<N && Y[y]<X[x]) x++;
            if (x<N) ans=max(y-x, ans);
        }
        cout << ans << '\n';
    }
}
