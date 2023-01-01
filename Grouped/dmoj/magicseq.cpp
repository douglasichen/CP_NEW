#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
    
    int N; cin>>N;
    vector<unsigned long long> dp(N+1); dp[1]=1;
    unsigned long long ans=1;
    for (int i=2; i<=N; i++) dp[i]=dp[i-1]+dp[i-2], ans+=dp[i];
    cout << ans << endl;
}