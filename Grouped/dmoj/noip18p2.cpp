#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);


    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        int a,b; cin>>a>>b;
        if (a>b) swap(a,b);
        if (b%a==0) {
            cout << 1 << endl;
        }
        else cout << 2 << endl;
    }    
}
