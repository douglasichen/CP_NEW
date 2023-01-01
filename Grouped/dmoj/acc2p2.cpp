#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define endl '\n'

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin>>N;
    char c;
    vector<vector<bool>> G(N, vector<bool>(N));
    vector<int> id(N);
    for (int y=0; y<N; y++)
        for (int x=0; x<N; x++)
            cin>>c, G[y][x]=(c=='1'), id[x]+=G[y][x];
    stack<int> Q;
    for (int i=0; i<N; i++) if (id[i]==0) Q.push(i);
    vector<int> ts;
    while (!Q.empty()) {
        int node=Q.top(); Q.pop();
        ts.push_back(node);
        for (int i=0; i<N; i++)
            if (G[node][i])
                if (--id[i]==0)
                    Q.push(i);
    }
    int ans=0;
    for (int i=0; i<N-1; i++)
        ans+=(!G[ts[i]][ts[i+1]]);
    cout << ans << endl;
}
=======

#define endl '\n'

void solve() {

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; cin>>N;
	char c;
	int cnt=0;
	for (int y=0; y<N; y++) {
		int a=1;
		for (int x=0; x<N; x++) {
			cin>>c;
			c-='0';
			if (c) a=0;
		}
		cnt+=a;
	}
	cout << cnt-1 << endl;
}
>>>>>>> 1432c1ee88857353d3fb117ea91e4454899448db
