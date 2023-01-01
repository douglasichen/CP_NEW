#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int P,K; cin>>P>>K;
    int N=P*20;
    string S(N,0);
    for (int i=0; i<N; i++) cin>>S[i];
    
    int D; cin>>D;
    vector<string> dict(D);
    for (int i=0; i<D; i++) cin>>dict[i];
    sort(dict.begin(), dict.end());

    vector<int> A(N+1);
    for (int i=0; i<N; i++) {
        for (string &d : dict) {
            if (i+d.size()<=N) {
                if (S.substr(i,d.size())==d) {
                    A[i+1]=d.size();
                    break;
                }
            }
        }
    }

    vector<vector<int>> dp(K+1, vector<int>(N+1));
    for (int k=1; k<=K; k++)
        for (int i=1; i<=N; i++)
            for (int gSz=1; gSz<=i-(k-1); gSz++) {
                int sm=0;
                for (int l=i-gSz+1; l<=i; l++)
                    sm+=(A[l]>0 && l+A[l]<=i+1);
                dp[k][i]=max(dp[k][i], dp[k-1][i-gSz]+sm);
            }
    cout << dp[K][N] << endl;
}
