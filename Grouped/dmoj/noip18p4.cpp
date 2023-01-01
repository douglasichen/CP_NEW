#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N,M; cin>>N>>M;
    vector<vector<int>> G(N+1);
    for (int i=0; i<M; i++) {
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (vector<int> &V : G) sort(V.begin(), V.end(), greater<int>()); 
    vector<int> vis(N+1);
    stack<int> S;
    vis[1]=1;
    S.push(1);
    vector<int> ans;
    while (!S.empty()) {
        int node=S.top(); S.pop();
        ans.push_back(node);
        for (int child : G[node]) {
            if (!vis[child])
                vis[child]=1,
                S.push(child);
        }
    }
    for (int i: ans) cout << i << ' '; cout << endl;

}
