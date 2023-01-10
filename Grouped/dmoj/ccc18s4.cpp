#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define SZ(x) int(x.size())
#define ms(x,y) memset(x,y,sizeof(x))

const int MAXN=100001;
bitset<1000000001> done;
unordered_map<int,ll> dp;
ll dp1[MAXN];

ll solve(int n) {
    if (n<MAXN && dp1[n]) return dp1[n];
    if (n>=MAXN && done[n]) return dp[n];

    ll ans=0;
    for (int k=2; k<=n; ) {
        int x=n/k;
        int k2=(n+x)/x;
        ans+=solve(x)*(k2-k);
        k=k2;
    }
    done[n]=1;
    if (n<MAXN) dp1[n]=ans;
    else dp[n]=ans;
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ms(dp1,0);
    
    dp1[1]=1;

    int N; cin>>N;
    cout << solve(N) << endl;
}
// k<(n+x)/x



