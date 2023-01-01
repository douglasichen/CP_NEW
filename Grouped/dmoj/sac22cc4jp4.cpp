#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long gcd(long long a, long long b) {
    while (b)
        a%=b,
        swap(a,b);
    return a;
}

long long lcm(long long a, long long b) {
    return a/gcd(a,b)*b;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

    int N;
    long long K; cin>>N>>K;
    vector<int> V(N);
    for (int &i : V) cin>>i, i--;
    
    vector<bool> vis(N);
    vector<int> cnts(N);
    long long a=1;
    for (int i=0; i<N; i++) {
        if (vis[i]) continue;
        vis[i]=1;
        int at=V[i], cnt=1;
        while (at!=i) vis[at]=1, at=V[at], cnt++;
        a=lcm(a,cnt);
        cnts[i]=cnt;
    }
    K%=a;
    vis=vector<bool>(N);
    vector<int> ans(N);
    for (int i=0; i<N; i++) {
        if (vis[i]) continue;
        int a=i, b=i, r=K%cnts[i];
        for (int k=0; k<r; k++) b=V[b];
        for (int c=0; c<cnts[i]; c++) {
            vis[a]=1;
            ans[b]=V[a]+1;
            a=V[a], b=V[b];
        }
    }
    for (int &i : ans) cout << i << ' '; cout << endl;
}