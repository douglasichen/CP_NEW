#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int c,r; cin>>c>>r;
    int a,b, A=0,B=0;
    cin>>a>>b; 
    while (a||b) {
        A+=a; B+=b;
        A=min(A,c); A=max(0,A);
        B=min(B,r); B=max(0,B);
        cout << A << ' ' << B << endl;
        cin>>a>>b;
    }   
}
