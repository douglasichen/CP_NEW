#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int N;

void out(vector<vector<int>> &G, int start) {
    stack<int> S;
    vector<bool> vis(N+1);
    vector<vector<int>> cons;
    int cnt=0;
    S.push(start); vis[start]=1;
    while (!S.empty()) {
        int top=S.top(); S.pop();
        cnt++;
        for (int child : G[top])
            if (!vis[child])
                vis[child]=1,
                cons.push_back({top,child}),
                S.push(child);
    }
    
    cout << cnt << endl;
    for (vector<int> v : cons)
        cout << v[0] << ' ' << v[1] << endl;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    vector<vector<int>> G(N+1), F=G;
    for (int i=1,a,b; i<N; i++) 
        cin>>a>>b,
        G[a].push_back(b),
        G[b].push_back(a);
    
    vector<int> from(N+1);
    stack<int> S; S.push(1);
    while (!S.empty()) {
        int node=S.top(); S.pop();
        if (from[from[node]]!=0)
            F[node].push_back(from[from[node]]),
            F[from[from[node]]].push_back(node);
        for (int child : G[node])
            if (child!=from[node])
                from[child]=node,
                S.push(child);
    }
    
    cout << G[1].size()+1 << endl;
    out(F,1);
    for (int child : G[1])
        out(F,child);
}