#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N,K; cin>>N>>K; K++;
    string S=" ";
    char c;
    for (int i=0; i<N; i++) cin>>c, S+=c;
    vector<vector<long long>> dp(K+1, vector<long long>(N+1,1));
    for (int k=1; k<=K; k++) {
        for (int i=1; i<=N; i++) {
            for (int sz=1; sz<=i-(k-1); sz++) {
                dp[k][i]=max(dp[k][i], dp[k-1][i-sz]*stol(S.substr(i-sz+1, sz)));
            }
        }
    }
    cout << dp[K][N] << endl;
}
