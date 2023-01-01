#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int r=1;
    while (r) {
        cin>>r;
        if (!r) return 0;
        ll ans=0;
        int x=1;
        for (int y=r-1; y; y--) {
            while(sqrt(y*y+(x+1)*(x+1))<=r) x++;
            ans+=x;
        }
        ans*=4;
        ans+=4*r+1;
        cout << ans << endl;
    }
}
