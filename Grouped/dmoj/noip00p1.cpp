#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N,R; cin>>N>>R;
    vector<char> V(10+26);
    for (int i=0; i<10; i++) V[i]=i+'0';
    for (int i=10; i<10+26; i++) V[i]='A'+i-10;
    string ans="";
    while (N) {
        int r=N%R;
        N/=R;
        if (r<0) r=(r-R)%abs(R), N++;
        ans+=V[r];
    }    
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
