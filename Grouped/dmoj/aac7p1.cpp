#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
	ll W,H;
    int T; cin>>T;
    while (T--) {
        cin>>W>>H;
        cout << (W*H>=7 && (W>=4 || H>=4) && W!=1 ? "good" : "bad") << '\n';
    }
}